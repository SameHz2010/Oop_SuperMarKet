using System;
using System.Linq;
using System.Windows.Forms;
using System.ComponentModel;
using SupermarketUI.Services;
using SupermarketUI.Models;

namespace SupermarketUI
{
    public partial class MainForm : Form
    {
        private readonly SupermarketService _svc;
        private BindingList<Product> _prodList;
        private BindingSource _prodSrc;
        // Customers
        private BindingList<Customer> _custList;
        private BindingSource _custSrc;

        // Employees
        private BindingList<Employee> _empList;
        private BindingSource _empSrc;
        private float currentDiscountRate = 0f;
        private float currentTaxRate = 0.05f;

        private BindingList<Bill> _invList;
        private BindingSource _invSrc;

        public MainForm()
        {
            InitializeComponent();

            // Initialize service before any grid setup
            _svc = new SupermarketService();

            // Setup inline editing for Products tab
            SetupInlineProductsGrid();
            SetupInlineCustomersGrid();
            SetupInlineEmployeesGrid();
            // Setup POS grids
            SetupPosGrids();

            // Wire up Load event
            this.Load += MainForm_Load;

            // Wire POS button clicks
            btnPosSearch.Click += btnPosSearch_Click;
            btnRemoveFromCart.Click += btnRemoveFromCart_Click;
            btnClearCart.Click += btnClearCart_Click;
            btnCheckout.Click += btnCheckout_Click;
            btnDeleteProduct.Click += btnDeleteProduct_Click;
            btnSearchProducts.Click += btnSearchProducts_Click;
            btnLoadCustomers.Click += (s, e) => { _svc.ReloadData(); RefreshCustomersGrid(); };
            btnRefreshCustomers.Click += (s, e) => RefreshCustomersGrid();

            btnLoadEmployees.Click += (s, e) => { _svc.ReloadData(); RefreshEmployeesGrid(); };
            btnRefreshEmployees.Click += (s, e) => RefreshEmployeesGrid();
            btnDeleteCustomer.Click += btnDeleteCustomer_Click;
            btnDeleteEmployee.Click += btnDeleteEmployee_Click;
            btnSearchEmployees.Click += btnSearchCustomers_Click;
            btnSearchEmployees.Click += btnSearchEmployees_Click;
            // Refresh POS when switching to POS tab
            tabControlMain.SelectedIndexChanged += (s, e) =>
            {
                if (tabControlMain.SelectedTab == POS)
                {
                    LoadPosProducts();
                    RefreshCart();
                }
            };
            SetupInvoiceGrid();
            btnSearchInvoice.Click += btnSearchInvoice_Click;
            btnRefreshInvoice.Click += (s, e) => RefreshInvoiceGrid();
            tabControlMain.SelectedIndexChanged += (s, e) => {
                if (tabControlMain.SelectedTab == tabPageInvoice)
                    RefreshInvoiceGrid();
            };
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            LoadPosProducts();
            RefreshCart();
        }

        private void LoadPosProducts()
        {
            var all = _svc.GetProducts();
            dgvPosProducts.DataSource = null;
            dgvPosProducts.DataSource = all;
        }

        private void btnPosSearch_Click(object sender, EventArgs e)
        {
            var term = txtPosSearch.Text.Trim();
            if (string.IsNullOrEmpty(term))
                LoadPosProducts();
            else
            {
                var filtered = _svc.GetProducts()
                    .Where(p => p.Name.Contains(term, StringComparison.OrdinalIgnoreCase)
                             || p.Id.Contains(term, StringComparison.OrdinalIgnoreCase))
                    .ToList();
                dgvPosProducts.DataSource = null;
                dgvPosProducts.DataSource = filtered;
            }
        }

        private void btnAddToCart_Click(object sender, EventArgs e)
        {
            if (dgvPosProducts.CurrentRow == null) return;
            var p = (Product)dgvPosProducts.CurrentRow.DataBoundItem;
            int qty = (int)nudPosQty.Value;
            nudPosQty.Value = 1;
            if (!_svc.AddToCart(p.Id, qty))
            {
                MessageBox.Show("Not enough stock.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            LoadPosProducts();
            RefreshCart();
        }

        private void RefreshCart()
        {
            var items = _svc.CurrentCart.Items.ToList();
            float subTotal = items.Sum(i => i.Subtotal);

            string custId = txtCustId.Text.Trim();
            float discountRate = _svc.FindCustomerById(custId)?.DiscountRate ?? 0f;
            float discountAmount = subTotal * discountRate;
            float taxAmount = (subTotal - discountAmount) * currentTaxRate;
            float total = subTotal - discountAmount + taxAmount;

            dgvPosCart.DataSource = null;
            dgvPosCart.DataSource = items;

            lblCartCount.Text = $"Cart: {items.Count} items";
            lblSubtotal.Text  = $"Subtotal: {subTotal:C}";
            lblDiscount.Text  = $"Discount: {discountAmount:C}";
            lblTax.Text       = $"Tax:      {taxAmount:C}";
            lblTotal.Text     = $"Total:    {total:C}";
        }

        private void btnRemoveFromCart_Click(object sender, EventArgs e)
        {
            if (dgvPosCart.CurrentRow == null) return;
            var item = (CartItem)dgvPosCart.CurrentRow.DataBoundItem;
            if (_svc.RemoveFromCart(item.Product.Id))
            {
                LoadPosProducts();
                RefreshCart();
            }
            else
            {
                MessageBox.Show("Failed to remove item.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnClearCart_Click(object sender, EventArgs e)
        {
            var result = MessageBox.Show("Are you sure you want to clear the entire cart?",
                                         "Confirm", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (result == DialogResult.Yes)
            {
                _svc.ClearCart();
                LoadPosProducts();
                RefreshCart();
            }
        }

        private void btnCheckout_Click(object sender, EventArgs e)
        {
            string custId = txtCustId.Text.Trim();
            var cust = _svc.FindCustomerById(custId);
            float discountRate = cust?.DiscountRate ?? 0f;
            float taxRate = currentTaxRate;
            string paymentMethod = comboPaymentMethod.Text;

            var bill = _svc.Checkout(
                customerId:    custId,
                employeeId:    /* e.g. currentEmployeeId */ "",
                discountRate:  discountRate,
                taxRate:       taxRate,
                payment:       paymentMethod
            );

            MessageBox.Show(
                $"Sale complete!\nInvoice: {bill.InvoiceId}\nTotal: {bill.Total:C}",
                "Checked out", MessageBoxButtons.OK, MessageBoxIcon.Information);

            LoadPosProducts();
            RefreshCart();
        }

        private void btnLookupCustomer_Click(object sender, EventArgs e)
        {
            RefreshCart();
        }

        private void SetupPosGrids()
        {
            dgvPosProducts.AutoGenerateColumns   = false;
            dgvPosProducts.AutoSizeColumnsMode   = DataGridViewAutoSizeColumnsMode.Fill;
            dgvPosProducts.Columns.Clear();

            dgvPosProducts.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name             = "colPosName",
                HeaderText       = "Name",
                DataPropertyName = "Name"
            });
            dgvPosProducts.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name             = "colPosPrice",
                HeaderText       = "Price",
                DataPropertyName = "Price",
                DefaultCellStyle = new DataGridViewCellStyle { Format = "C" }
            });
            dgvPosProducts.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name             = "colPosQty",
                HeaderText       = "Qty",
                DataPropertyName = "Quantity"
            });

            dgvPosCart.AutoGenerateColumns       = false;
            dgvPosCart.AutoSizeColumnsMode       = DataGridViewAutoSizeColumnsMode.Fill;
            dgvPosCart.Columns.Clear();

            dgvPosCart.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name             = "colCartName",
                HeaderText       = "Name",
                DataPropertyName = "ProductName"
            });
            dgvPosCart.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name             = "colCartQty",
                HeaderText       = "Qty",
                DataPropertyName = "Quantity"
            });
            dgvPosCart.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name             = "colCartSubtotal",
                HeaderText       = "Subtotal",
                DataPropertyName = "Subtotal",
                DefaultCellStyle = new DataGridViewCellStyle { Format = "C" }
            });
        }

        private void SetupInlineProductsGrid()
        {
            // 1) Bind your in-memory list
            _prodList = new BindingList<Product>(_svc.GetProducts())
            {
                AllowNew = true,
                AllowEdit = true,
                AllowRemove = true
            };
            _prodSrc = new BindingSource { DataSource = _prodList };

            // 2) Configure the DataGridView
            dgvProducts.AutoGenerateColumns = false;
            dgvProducts.DataSource = _prodSrc;
            dgvProducts.AllowUserToAddRows = true;
            dgvProducts.AllowUserToDeleteRows = true;
            dgvProducts.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dgvProducts.EditMode = DataGridViewEditMode.EditOnEnter;

            // 3) Define columns
            dgvProducts.Columns.Clear();
            dgvProducts.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name = "colProdId",
                HeaderText = "ID",
                DataPropertyName = "Id"
            });
            dgvProducts.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name = "colProdName",
                HeaderText = "Name",
                DataPropertyName = "Name"
            });
            dgvProducts.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name = "colProdPrice",
                HeaderText = "Price",
                DataPropertyName = "Price",
                DefaultCellStyle = new DataGridViewCellStyle { Format = "C" }
            });
            dgvProducts.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name = "colProdQty",
                HeaderText = "Qty",
                DataPropertyName = "Quantity"
            });

            // 4) Handle parse/binding errors (e.g., when cells are empty)
            dgvProducts.DataError += (s, e) =>
            {
                e.ThrowException = false;
                e.Cancel = true;
            };

            // 5) Persist changes on CellEndEdit (instead of RowValidated to avoid deletion issues)
            dgvProducts.CellEndEdit += new DataGridViewCellEventHandler((s, e) =>
            {
                if (e.RowIndex < 0 || e.RowIndex >= dgvProducts.Rows.Count) return;
                var row = dgvProducts.Rows[e.RowIndex];
                if (row.IsNewRow) return;

                var p = row.DataBoundItem as Product;
                if (p == null) return;

                if (_svc.FindProductById(p.Id) == null)
                    _svc.AddProduct(p);
                else
                    _svc.UpdateProduct(p);
            });

            // 6) Handle deletes via the grid (e.g., pressing Delete key)
            dgvProducts.UserDeletingRow += new DataGridViewRowCancelEventHandler((s, e) =>
            {
                var p = e.Row.DataBoundItem as Product;
                if (p != null)
                    _svc.DeleteProduct(p.Id);
            });
        }

        private void btnDeleteProduct_Click(object sender, EventArgs e)
        {
            if (dgvProducts.CurrentRow == null) return;
            var p = (Product)dgvProducts.CurrentRow.DataBoundItem;
            if (MessageBox.Show($"Delete {p.Name}?", "Confirm", MessageBoxButtons.YesNo)
                != DialogResult.Yes) return;
            _prodList.Remove(p);        // removes from grid
            _svc.DeleteProduct(p.Id);   // persists to CSV
        }
        private void btnSearchProducts_Click(object sender, EventArgs e)
        {
            string term = txtSearchProducts.Text.Trim();
            // pull either the full list or just matching ones
            var list = string.IsNullOrEmpty(term)
                ? _svc.GetProducts()
                : _svc.SearchProducts(term);

            // re‑create your binding list around that data
            _prodList = new BindingList<Product>(list)
            {
                AllowNew = true,
                AllowEdit = true,
                AllowRemove = true
            };
            // swap it into the existing source
            _prodSrc.DataSource = _prodList;

            // grid is already configured to pick up CellEndEdit and deletes,
            // so you don’t need to re‑call SetupInlineProductsGrid()
        }
        private void RefreshCustomersGrid()
        {
            _custList = new BindingList<Customer>(_svc.GetCustomers())
            {
                AllowNew = true,
                AllowEdit = true,
                AllowRemove = true
            };
            _custSrc.DataSource = _custList;
        }

        private void RefreshEmployeesGrid()
        {
            _empList = new BindingList<Employee>(_svc.GetEmployees())
            {
                AllowNew = true,
                AllowEdit = true,
                AllowRemove = true
            };
            _empSrc.DataSource = _empList;
        }
        private void SetupInlineCustomersGrid()
        {
            _custList = new BindingList<Customer>(_svc.GetCustomers()) { AllowNew = true, AllowEdit = true, AllowRemove = true };
            _custSrc = new BindingSource { DataSource = _custList };

            dgvCustomers.AutoGenerateColumns = false;
            dgvCustomers.DataSource = _custSrc;
            dgvCustomers.AllowUserToAddRows = true;
            dgvCustomers.AllowUserToDeleteRows = true;
            dgvCustomers.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dgvCustomers.EditMode = DataGridViewEditMode.EditOnEnter;

            dgvCustomers.Columns.Clear();
            dgvCustomers.Columns.Add(new DataGridViewTextBoxColumn { Name = "colCustId", HeaderText = "ID", DataPropertyName = "Id" });
            dgvCustomers.Columns.Add(new DataGridViewTextBoxColumn { Name = "colCustName", HeaderText = "Name", DataPropertyName = "Name" });
            dgvCustomers.Columns.Add(new DataGridViewTextBoxColumn { Name = "colCustPhone", HeaderText = "Phone", DataPropertyName = "Phone" });
            dgvCustomers.Columns.Add(new DataGridViewTextBoxColumn { Name = "colCustType", HeaderText = "Member Type", DataPropertyName = "MemberType" });
            dgvCustomers.Columns.Add(new DataGridViewTextBoxColumn { Name = "colCustPoints", HeaderText = "Loyalty Points", DataPropertyName = "LoyaltyPoints" });

            dgvCustomers.DataError += (s, e) => { e.ThrowException = false; e.Cancel = true; };
            dgvCustomers.CellEndEdit += (s, e) =>
            {
                if (e.RowIndex < 0 || e.RowIndex >= dgvCustomers.Rows.Count) return;
                var row = dgvCustomers.Rows[e.RowIndex]; if (row.IsNewRow) return;
                var c = row.DataBoundItem as Customer; if (c == null) return;
                if (_svc.FindCustomerById(c.Id) == null) _svc.AddCustomer(c);
                else _svc.UpdateCustomer(c);
            };
            dgvCustomers.UserDeletingRow += (s, e) =>
            {
                var c = e.Row.DataBoundItem as Customer; if (c != null) _svc.DeleteCustomer(c.Id);
            };
        }

        private void SetupInlineEmployeesGrid()
        {
            _empList = new BindingList<Employee>(_svc.GetEmployees()) { AllowNew = true, AllowEdit = true, AllowRemove = true };
            _empSrc = new BindingSource { DataSource = _empList };

            dgvEmployees.AutoGenerateColumns = false;
            dgvEmployees.DataSource = _empSrc;
            dgvEmployees.AllowUserToAddRows = true;
            dgvEmployees.AllowUserToDeleteRows = true;
            dgvEmployees.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dgvEmployees.EditMode = DataGridViewEditMode.EditOnEnter;

            dgvEmployees.Columns.Clear();
            dgvEmployees.Columns.Add(new DataGridViewTextBoxColumn { Name = "colEmpId", HeaderText = "ID", DataPropertyName = "Id" });
            dgvEmployees.Columns.Add(new DataGridViewTextBoxColumn { Name = "colEmpName", HeaderText = "Name", DataPropertyName = "Name" });
            dgvEmployees.Columns.Add(new DataGridViewTextBoxColumn { Name = "colEmpPhone", HeaderText = "Phone", DataPropertyName = "Phone" });
            dgvEmployees.Columns.Add(new DataGridViewTextBoxColumn { Name = "colEmpPos", HeaderText = "Position", DataPropertyName = "Position" });
            dgvEmployees.Columns.Add(new DataGridViewTextBoxColumn { Name = "colEmpSalary", HeaderText = "Salary", DataPropertyName = "Salary" });
            dgvEmployees.Columns.Add(new DataGridViewTextBoxColumn { Name = "colEmpDate", HeaderText = "Date Hired", DataPropertyName = "DateHired" });

            dgvEmployees.DataError += (s, e) => { e.ThrowException = false; e.Cancel = true; };
            dgvEmployees.CellEndEdit += (s, e) =>
            {
                if (e.RowIndex < 0 || e.RowIndex >= dgvEmployees.Rows.Count) return;
                var row = dgvEmployees.Rows[e.RowIndex]; if (row.IsNewRow) return;
                var emp = row.DataBoundItem as Employee; if (emp == null) return;
                if (_svc.FindEmployeeById(emp.Id) == null) _svc.AddEmployee(emp);
                else _svc.UpdateEmployee(emp);
            };
            dgvEmployees.UserDeletingRow += (s, e) =>
            {
                var emp = e.Row.DataBoundItem as Employee; if (emp != null) _svc.DeleteEmployee(emp.Id);
            };
        }
        private void btnDeleteCustomer_Click(object sender, EventArgs e)
        {
            if (dgvCustomers.CurrentRow == null) return;
            var c = (Customer)dgvCustomers.CurrentRow.DataBoundItem;
            if (MessageBox.Show($"Delete {c.Name}?", "Confirm", MessageBoxButtons.YesNo)
                != DialogResult.Yes) return;
            _custList.Remove(c);
            _svc.DeleteCustomer(c.Id);
        }

        private void btnDeleteEmployee_Click(object sender, EventArgs e)
        {
            if (dgvEmployees.CurrentRow == null) return;
            var emp = (Employee)dgvEmployees.CurrentRow.DataBoundItem;
            if (MessageBox.Show($"Delete {emp.Name}?", "Confirm", MessageBoxButtons.YesNo)
                != DialogResult.Yes) return;
            _empList.Remove(emp);
            _svc.DeleteEmployee(emp.Id);
        }
        // Customers search
        private void btnSearchCustomers_Click(object sender, EventArgs e)
        {
            string term = txtSearchCustomers.Text.Trim();
            var list = string.IsNullOrEmpty(term)
                ? _svc.GetCustomers()
                : _svc.SearchCustomers(term);  // already filters by Name

            _custList = new BindingList<Customer>(list)
            {
                AllowNew = true,
                AllowEdit = true,
                AllowRemove = true
            };
            _custSrc.DataSource = _custList;
        }

        // Employees search
        private void btnSearchEmployees_Click(object sender, EventArgs e)
        {
            string term = txtSearchEmployees.Text.Trim();
            List<Employee> list;

            if (string.IsNullOrEmpty(term))
            {
                list = _svc.GetEmployees();
            }
            else
            {
                // filter by Name or ID
                list = _svc.GetEmployees()
                    .Where(emp =>
                        emp.Name.Contains(term, StringComparison.OrdinalIgnoreCase) ||
                        emp.Id.Contains(term, StringComparison.OrdinalIgnoreCase))
                    .ToList();
            }

            _empList = new BindingList<Employee>(list)
            {
                AllowNew = true,
                AllowEdit = true,
                AllowRemove = true
            };
            _empSrc.DataSource = _empList;
        }

        private void SetupInvoiceGrid()
        {
            _invList = new BindingList<Bill>(_svc.GetBills());
            _invSrc = new BindingSource { DataSource = _invList };
            dgvInvoices.AutoGenerateColumns = false;
            dgvInvoices.DataSource = _invSrc;
            dgvInvoices.AllowUserToAddRows = false;
            dgvInvoices.AllowUserToDeleteRows = false;
            dgvInvoices.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dgvInvoices.Columns.Clear();
            dgvInvoices.Columns.Add(new DataGridViewTextBoxColumn { Name = "colInvoiceId", HeaderText = "Invoice ID", DataPropertyName = "InvoiceId" });
            dgvInvoices.Columns.Add(new DataGridViewTextBoxColumn { Name = "colInvCust", HeaderText = "Customer ID", DataPropertyName = "CustomerId" });
            dgvInvoices.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name = "colInvDate",
                HeaderText = "Date",
                DataPropertyName = "Date",
                DefaultCellStyle = new DataGridViewCellStyle
                {
                    // "d" is the short date pattern (e.g. 4/18/2025). 
                    // Or use "yyyy-MM-dd" if you prefer ISO style.
                    Format = "d"
                }
            });
            dgvInvoices.Columns.Add(new DataGridViewTextBoxColumn { Name = "colInvDiscount", HeaderText = "Discount", DataPropertyName = "Discount", DefaultCellStyle = new DataGridViewCellStyle { Format = "C" } });
            dgvInvoices.Columns.Add(new DataGridViewTextBoxColumn { Name = "colInvTax", HeaderText = "Tax", DataPropertyName = "Tax", DefaultCellStyle = new DataGridViewCellStyle { Format = "C" } });
            dgvInvoices.Columns.Add(new DataGridViewTextBoxColumn { Name = "colInvTotal", HeaderText = "Total", DataPropertyName = "Total", DefaultCellStyle = new DataGridViewCellStyle { Format = "C" } });

            // After you finish configuring dgvInvoices, also set up the items grid:
            dgvInvoiceItems.AutoGenerateColumns = false;
            dgvInvoiceItems.AllowUserToAddRows = false;
            dgvInvoiceItems.AllowUserToDeleteRows = false;
            dgvInvoiceItems.ReadOnly = true;
            dgvInvoiceItems.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dgvInvoiceItems.Columns.Clear();

            dgvInvoiceItems.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name = "colItemProdName",
                HeaderText = "Product Name",
                DataPropertyName = "ProductName"
            });
            dgvInvoiceItems.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name = "colItemQty",
                HeaderText = "Qty",
                DataPropertyName = "Quantity"
            });
            dgvInvoiceItems.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name = "colItemPrice",
                HeaderText = "Unit Price",
                DataPropertyName = "Price",
                DefaultCellStyle = new DataGridViewCellStyle { Format = "C" }
            });
            dgvInvoiceItems.Columns.Add(new DataGridViewTextBoxColumn
            {
                Name = "colItemSubtotal",
                HeaderText = "Subtotal",
                DataPropertyName = "Subtotal",
                DefaultCellStyle = new DataGridViewCellStyle { Format = "C" }
            });

            // When the user selects a different invoice, fill this grid:
            dgvInvoices.SelectionChanged += dgvInvoices_SelectionChanged;

            dgvInvoices.Columns["colInvoiceId"].FillWeight = 80;
            dgvInvoices.Columns["colInvCust"].FillWeight = 80;
            dgvInvoices.Columns["colInvDate"].FillWeight = 100;
            dgvInvoices.Columns["colInvDiscount"].FillWeight = 80;
            dgvInvoices.Columns["colInvTax"].FillWeight = 80;
            dgvInvoices.Columns["colInvTotal"].FillWeight = 100;
        }

        private void RefreshInvoiceGrid()
        {
            _invList = new BindingList<Bill>(_svc.GetBills());
            _invSrc.DataSource = _invList;
        }

        private void btnSearchInvoice_Click(object sender, EventArgs e)
        {
            var id = txtSearchInvoice.Text.Trim();
            if (string.IsNullOrEmpty(id))
                RefreshInvoiceGrid();
            else
            {
                var bill = _svc.FindBill(id);
                _invList = bill != null
                  ? new BindingList<Bill>(new[] { bill })
                  : new BindingList<Bill>();
                _invSrc.DataSource = _invList;
            }
        }

        private void dgvInvoices_SelectionChanged(object sender, EventArgs e)
        {
            if (dgvInvoices.CurrentRow == null)
            {
                dgvInvoiceItems.DataSource = null;
                return;
            }

            // Grab the selected invoice (Bill)
            var bill = (Bill)dgvInvoices.CurrentRow.DataBoundItem;
            if (bill == null)
            {
                dgvInvoiceItems.DataSource = null;
                return;
            }

            // Project each CartItem into a simple object for the grid
            var items = bill.Items
                .Select(ci => new {
                    ProductId = ci.Product.Id,
                    ProductName = ci.Product.Name,
                    Quantity = ci.Quantity,
                    Price = ci.Product.Price,
                    Subtotal = ci.Subtotal
                })
                .ToList();

            dgvInvoiceItems.DataSource = items;
        }
    }
}
