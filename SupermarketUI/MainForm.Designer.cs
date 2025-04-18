namespace SupermarketUI
{
    partial class MainForm
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            productBindingSource = new BindingSource(components);
            tabPageInvoice = new TabPage();
            splitContainer2 = new SplitContainer();
            dgvInvoices = new DataGridView();
            dgvInvoiceItems = new DataGridView();
            panel4 = new Panel();
            btnSearchInvoice = new Button();
            txtSearchInvoice = new TextBox();
            btnRefreshInvoice = new Button();
            Employee = new TabPage();
            dgvEmployees = new DataGridView();
            panel3 = new Panel();
            btnSearchEmployees = new Button();
            txtSearchEmployees = new TextBox();
            btnDeleteEmployee = new Button();
            btnRefreshEmployees = new Button();
            btnLoadEmployees = new Button();
            Customer = new TabPage();
            dgvCustomers = new DataGridView();
            panel2 = new Panel();
            btnSearchCustomers = new Button();
            txtSearchCustomers = new TextBox();
            btnDeleteCustomer = new Button();
            btnRefreshCustomers = new Button();
            btnLoadCustomers = new Button();
            Products = new TabPage();
            dgvProducts = new DataGridView();
            panelProductsToolbar = new Panel();
            btnSearchProducts = new Button();
            txtSearchProducts = new TextBox();
            btnDeleteProduct = new Button();
            btnRefreshProducts = new Button();
            btnLoadProducts = new Button();
            POS = new TabPage();
            splitContainer1 = new SplitContainer();
            label2221 = new Label();
            btnAddToCart = new Button();
            nudPosQty = new NumericUpDown();
            dgvPosProducts = new DataGridView();
            BTN321 = new Button();
            lblTax = new Label();
            lblDiscount = new Label();
            lblSubtotal = new Label();
            comboPaymentMethod = new ComboBox();
            label1213213123 = new Label();
            txtCustId = new TextBox();
            label3123123 = new Label();
            btnCheckout = new Button();
            btnClearCart = new Button();
            btnRemoveFromCart = new Button();
            lblTotal = new Label();
            dgvPosCart = new DataGridView();
            panel1 = new Panel();
            label2 = new Label();
            lblCartCount = new Label();
            btnPosSearch = new Button();
            txtPosSearch = new TextBox();
            tabControlMain = new TabControl();
            ((System.ComponentModel.ISupportInitialize)productBindingSource).BeginInit();
            tabPageInvoice.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)splitContainer2).BeginInit();
            splitContainer2.Panel1.SuspendLayout();
            splitContainer2.Panel2.SuspendLayout();
            splitContainer2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)dgvInvoices).BeginInit();
            ((System.ComponentModel.ISupportInitialize)dgvInvoiceItems).BeginInit();
            panel4.SuspendLayout();
            Employee.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)dgvEmployees).BeginInit();
            panel3.SuspendLayout();
            Customer.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)dgvCustomers).BeginInit();
            panel2.SuspendLayout();
            Products.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)dgvProducts).BeginInit();
            panelProductsToolbar.SuspendLayout();
            POS.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)splitContainer1).BeginInit();
            splitContainer1.Panel1.SuspendLayout();
            splitContainer1.Panel2.SuspendLayout();
            splitContainer1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)nudPosQty).BeginInit();
            ((System.ComponentModel.ISupportInitialize)dgvPosProducts).BeginInit();
            ((System.ComponentModel.ISupportInitialize)dgvPosCart).BeginInit();
            panel1.SuspendLayout();
            tabControlMain.SuspendLayout();
            SuspendLayout();
            // 
            // productBindingSource
            // 
            productBindingSource.DataSource = typeof(Models.Product);
            // 
            // tabPageInvoice
            // 
            tabPageInvoice.Controls.Add(splitContainer2);
            tabPageInvoice.Controls.Add(panel4);
            tabPageInvoice.Location = new Point(4, 24);
            tabPageInvoice.Name = "tabPageInvoice";
            tabPageInvoice.Padding = new Padding(3);
            tabPageInvoice.Size = new Size(697, 503);
            tabPageInvoice.TabIndex = 7;
            tabPageInvoice.Text = "Invoice";
            tabPageInvoice.UseVisualStyleBackColor = true;
            // 
            // splitContainer2
            // 
            splitContainer2.Dock = DockStyle.Fill;
            splitContainer2.Location = new Point(3, 53);
            splitContainer2.Name = "splitContainer2";
            // 
            // splitContainer2.Panel1
            // 
            splitContainer2.Panel1.Controls.Add(dgvInvoices);
            // 
            // splitContainer2.Panel2
            // 
            splitContainer2.Panel2.Controls.Add(dgvInvoiceItems);
            splitContainer2.Size = new Size(691, 447);
            splitContainer2.SplitterDistance = 425;
            splitContainer2.TabIndex = 2;
            // 
            // dgvInvoices
            // 
            dgvInvoices.AllowUserToAddRows = false;
            dgvInvoices.AllowUserToDeleteRows = false;
            dgvInvoices.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dgvInvoices.Dock = DockStyle.Fill;
            dgvInvoices.EditMode = DataGridViewEditMode.EditProgrammatically;
            dgvInvoices.Location = new Point(0, 0);
            dgvInvoices.Name = "dgvInvoices";
            dgvInvoices.RowHeadersVisible = false;
            dgvInvoices.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            dgvInvoices.Size = new Size(425, 447);
            dgvInvoices.TabIndex = 0;
            // 
            // dgvInvoiceItems
            // 
            dgvInvoiceItems.AllowUserToAddRows = false;
            dgvInvoiceItems.AllowUserToDeleteRows = false;
            dgvInvoiceItems.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dgvInvoiceItems.Dock = DockStyle.Fill;
            dgvInvoiceItems.EditMode = DataGridViewEditMode.EditProgrammatically;
            dgvInvoiceItems.Location = new Point(0, 0);
            dgvInvoiceItems.Name = "dgvInvoiceItems";
            dgvInvoiceItems.RowHeadersVisible = false;
            dgvInvoiceItems.Size = new Size(262, 447);
            dgvInvoiceItems.TabIndex = 0;
            // 
            // panel4
            // 
            panel4.Controls.Add(btnSearchInvoice);
            panel4.Controls.Add(txtSearchInvoice);
            panel4.Controls.Add(btnRefreshInvoice);
            panel4.Dock = DockStyle.Top;
            panel4.Location = new Point(3, 3);
            panel4.MaximumSize = new Size(0, 50);
            panel4.MinimumSize = new Size(0, 50);
            panel4.Name = "panel4";
            panel4.Size = new Size(691, 50);
            panel4.TabIndex = 0;
            // 
            // btnSearchInvoice
            // 
            btnSearchInvoice.Location = new Point(601, 13);
            btnSearchInvoice.Name = "btnSearchInvoice";
            btnSearchInvoice.Size = new Size(75, 23);
            btnSearchInvoice.TabIndex = 6;
            btnSearchInvoice.Text = "Search";
            btnSearchInvoice.UseVisualStyleBackColor = true;
            // 
            // txtSearchInvoice
            // 
            txtSearchInvoice.Location = new Point(421, 13);
            txtSearchInvoice.MinimumSize = new Size(150, 0);
            txtSearchInvoice.Name = "txtSearchInvoice";
            txtSearchInvoice.PlaceholderText = "Search: ";
            txtSearchInvoice.Size = new Size(174, 23);
            txtSearchInvoice.TabIndex = 5;
            // 
            // btnRefreshInvoice
            // 
            btnRefreshInvoice.Location = new Point(5, 12);
            btnRefreshInvoice.Name = "btnRefreshInvoice";
            btnRefreshInvoice.Size = new Size(75, 23);
            btnRefreshInvoice.TabIndex = 1;
            btnRefreshInvoice.Text = "Refresh";
            btnRefreshInvoice.UseVisualStyleBackColor = true;
            // 
            // Employee
            // 
            Employee.Controls.Add(dgvEmployees);
            Employee.Controls.Add(panel3);
            Employee.Location = new Point(4, 24);
            Employee.Name = "Employee";
            Employee.Padding = new Padding(3);
            Employee.Size = new Size(697, 503);
            Employee.TabIndex = 6;
            Employee.Text = "Employee";
            Employee.UseVisualStyleBackColor = true;
            // 
            // dgvEmployees
            // 
            dgvEmployees.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dgvEmployees.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dgvEmployees.Dock = DockStyle.Fill;
            dgvEmployees.Location = new Point(3, 53);
            dgvEmployees.Name = "dgvEmployees";
            dgvEmployees.RowHeadersVisible = false;
            dgvEmployees.Size = new Size(691, 447);
            dgvEmployees.TabIndex = 1;
            // 
            // panel3
            // 
            panel3.Controls.Add(btnSearchEmployees);
            panel3.Controls.Add(txtSearchEmployees);
            panel3.Controls.Add(btnDeleteEmployee);
            panel3.Controls.Add(btnRefreshEmployees);
            panel3.Controls.Add(btnLoadEmployees);
            panel3.Dock = DockStyle.Top;
            panel3.Location = new Point(3, 3);
            panel3.MaximumSize = new Size(0, 50);
            panel3.MinimumSize = new Size(0, 50);
            panel3.Name = "panel3";
            panel3.Size = new Size(691, 50);
            panel3.TabIndex = 0;
            // 
            // btnSearchEmployees
            // 
            btnSearchEmployees.Location = new Point(521, 13);
            btnSearchEmployees.Name = "btnSearchEmployees";
            btnSearchEmployees.Size = new Size(75, 23);
            btnSearchEmployees.TabIndex = 6;
            btnSearchEmployees.Text = "Search";
            btnSearchEmployees.UseVisualStyleBackColor = true;
            // 
            // txtSearchEmployees
            // 
            txtSearchEmployees.Location = new Point(341, 13);
            txtSearchEmployees.MinimumSize = new Size(150, 0);
            txtSearchEmployees.Name = "txtSearchEmployees";
            txtSearchEmployees.PlaceholderText = "Search: ";
            txtSearchEmployees.Size = new Size(174, 23);
            txtSearchEmployees.TabIndex = 5;
            // 
            // btnDeleteEmployee
            // 
            btnDeleteEmployee.Location = new Point(602, 13);
            btnDeleteEmployee.Name = "btnDeleteEmployee";
            btnDeleteEmployee.Size = new Size(75, 23);
            btnDeleteEmployee.TabIndex = 4;
            btnDeleteEmployee.Text = "Delete";
            btnDeleteEmployee.UseVisualStyleBackColor = true;
            // 
            // btnRefreshEmployees
            // 
            btnRefreshEmployees.Location = new Point(86, 15);
            btnRefreshEmployees.Name = "btnRefreshEmployees";
            btnRefreshEmployees.Size = new Size(75, 23);
            btnRefreshEmployees.TabIndex = 1;
            btnRefreshEmployees.Text = "Refresh";
            btnRefreshEmployees.UseVisualStyleBackColor = true;
            // 
            // btnLoadEmployees
            // 
            btnLoadEmployees.Location = new Point(5, 15);
            btnLoadEmployees.Name = "btnLoadEmployees";
            btnLoadEmployees.Size = new Size(75, 23);
            btnLoadEmployees.TabIndex = 0;
            btnLoadEmployees.Text = "Load CSV";
            btnLoadEmployees.UseVisualStyleBackColor = true;
            // 
            // Customer
            // 
            Customer.Controls.Add(dgvCustomers);
            Customer.Controls.Add(panel2);
            Customer.Location = new Point(4, 24);
            Customer.Name = "Customer";
            Customer.Padding = new Padding(3);
            Customer.Size = new Size(697, 503);
            Customer.TabIndex = 5;
            Customer.Text = "Customer";
            Customer.UseVisualStyleBackColor = true;
            // 
            // dgvCustomers
            // 
            dgvCustomers.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dgvCustomers.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dgvCustomers.Dock = DockStyle.Fill;
            dgvCustomers.EditMode = DataGridViewEditMode.EditOnEnter;
            dgvCustomers.Location = new Point(3, 53);
            dgvCustomers.Name = "dgvCustomers";
            dgvCustomers.RowHeadersVisible = false;
            dgvCustomers.Size = new Size(691, 447);
            dgvCustomers.TabIndex = 1;
            // 
            // panel2
            // 
            panel2.Controls.Add(btnSearchCustomers);
            panel2.Controls.Add(txtSearchCustomers);
            panel2.Controls.Add(btnDeleteCustomer);
            panel2.Controls.Add(btnRefreshCustomers);
            panel2.Controls.Add(btnLoadCustomers);
            panel2.Dock = DockStyle.Top;
            panel2.Location = new Point(3, 3);
            panel2.MaximumSize = new Size(0, 50);
            panel2.MinimumSize = new Size(0, 50);
            panel2.Name = "panel2";
            panel2.Size = new Size(691, 50);
            panel2.TabIndex = 0;
            // 
            // btnSearchCustomers
            // 
            btnSearchCustomers.Location = new Point(521, 13);
            btnSearchCustomers.Name = "btnSearchCustomers";
            btnSearchCustomers.Size = new Size(75, 23);
            btnSearchCustomers.TabIndex = 6;
            btnSearchCustomers.Text = "Search";
            btnSearchCustomers.UseVisualStyleBackColor = true;
            // 
            // txtSearchCustomers
            // 
            txtSearchCustomers.Location = new Point(341, 13);
            txtSearchCustomers.MinimumSize = new Size(150, 0);
            txtSearchCustomers.Name = "txtSearchCustomers";
            txtSearchCustomers.PlaceholderText = "Search: ";
            txtSearchCustomers.Size = new Size(174, 23);
            txtSearchCustomers.TabIndex = 5;
            // 
            // btnDeleteCustomer
            // 
            btnDeleteCustomer.Location = new Point(602, 13);
            btnDeleteCustomer.Name = "btnDeleteCustomer";
            btnDeleteCustomer.Size = new Size(75, 23);
            btnDeleteCustomer.TabIndex = 4;
            btnDeleteCustomer.Text = "Delete";
            btnDeleteCustomer.UseVisualStyleBackColor = true;
            // 
            // btnRefreshCustomers
            // 
            btnRefreshCustomers.Location = new Point(86, 15);
            btnRefreshCustomers.Name = "btnRefreshCustomers";
            btnRefreshCustomers.Size = new Size(75, 23);
            btnRefreshCustomers.TabIndex = 1;
            btnRefreshCustomers.Text = "Refresh";
            btnRefreshCustomers.UseVisualStyleBackColor = true;
            // 
            // btnLoadCustomers
            // 
            btnLoadCustomers.Location = new Point(5, 15);
            btnLoadCustomers.Name = "btnLoadCustomers";
            btnLoadCustomers.Size = new Size(75, 23);
            btnLoadCustomers.TabIndex = 0;
            btnLoadCustomers.Text = "Load CSV";
            btnLoadCustomers.UseVisualStyleBackColor = true;
            // 
            // Products
            // 
            Products.Controls.Add(dgvProducts);
            Products.Controls.Add(panelProductsToolbar);
            Products.Location = new Point(4, 24);
            Products.Name = "Products";
            Products.Padding = new Padding(3);
            Products.Size = new Size(697, 503);
            Products.TabIndex = 1;
            Products.Text = "Products";
            Products.UseVisualStyleBackColor = true;
            // 
            // dgvProducts
            // 
            dgvProducts.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dgvProducts.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dgvProducts.Dock = DockStyle.Fill;
            dgvProducts.EditMode = DataGridViewEditMode.EditOnEnter;
            dgvProducts.Location = new Point(3, 53);
            dgvProducts.Name = "dgvProducts";
            dgvProducts.RowHeadersVisible = false;
            dgvProducts.Size = new Size(691, 447);
            dgvProducts.TabIndex = 1;
            // 
            // panelProductsToolbar
            // 
            panelProductsToolbar.Controls.Add(btnSearchProducts);
            panelProductsToolbar.Controls.Add(txtSearchProducts);
            panelProductsToolbar.Controls.Add(btnDeleteProduct);
            panelProductsToolbar.Controls.Add(btnRefreshProducts);
            panelProductsToolbar.Controls.Add(btnLoadProducts);
            panelProductsToolbar.Dock = DockStyle.Top;
            panelProductsToolbar.Location = new Point(3, 3);
            panelProductsToolbar.MaximumSize = new Size(0, 50);
            panelProductsToolbar.MinimumSize = new Size(0, 50);
            panelProductsToolbar.Name = "panelProductsToolbar";
            panelProductsToolbar.Size = new Size(691, 50);
            panelProductsToolbar.TabIndex = 0;
            // 
            // btnSearchProducts
            // 
            btnSearchProducts.Location = new Point(521, 13);
            btnSearchProducts.Name = "btnSearchProducts";
            btnSearchProducts.Size = new Size(75, 23);
            btnSearchProducts.TabIndex = 6;
            btnSearchProducts.Text = "Search";
            btnSearchProducts.UseVisualStyleBackColor = true;
            // 
            // txtSearchProducts
            // 
            txtSearchProducts.Location = new Point(341, 13);
            txtSearchProducts.MinimumSize = new Size(150, 0);
            txtSearchProducts.Name = "txtSearchProducts";
            txtSearchProducts.PlaceholderText = "Search: ";
            txtSearchProducts.Size = new Size(174, 23);
            txtSearchProducts.TabIndex = 5;
            // 
            // btnDeleteProduct
            // 
            btnDeleteProduct.Location = new Point(602, 13);
            btnDeleteProduct.Name = "btnDeleteProduct";
            btnDeleteProduct.Size = new Size(75, 23);
            btnDeleteProduct.TabIndex = 4;
            btnDeleteProduct.Text = "Delete";
            btnDeleteProduct.UseVisualStyleBackColor = true;
            // 
            // btnRefreshProducts
            // 
            btnRefreshProducts.Location = new Point(86, 15);
            btnRefreshProducts.Name = "btnRefreshProducts";
            btnRefreshProducts.Size = new Size(75, 23);
            btnRefreshProducts.TabIndex = 1;
            btnRefreshProducts.Text = "Refresh";
            btnRefreshProducts.UseVisualStyleBackColor = true;
            // 
            // btnLoadProducts
            // 
            btnLoadProducts.Location = new Point(5, 15);
            btnLoadProducts.Name = "btnLoadProducts";
            btnLoadProducts.Size = new Size(75, 23);
            btnLoadProducts.TabIndex = 0;
            btnLoadProducts.Text = "Load CSV";
            btnLoadProducts.UseVisualStyleBackColor = true;
            // 
            // POS
            // 
            POS.Controls.Add(splitContainer1);
            POS.Controls.Add(panel1);
            POS.Location = new Point(4, 24);
            POS.Name = "POS";
            POS.Padding = new Padding(3);
            POS.Size = new Size(697, 503);
            POS.TabIndex = 0;
            POS.Text = "POS";
            POS.UseVisualStyleBackColor = true;
            // 
            // splitContainer1
            // 
            splitContainer1.Dock = DockStyle.Fill;
            splitContainer1.Location = new Point(3, 48);
            splitContainer1.Name = "splitContainer1";
            // 
            // splitContainer1.Panel1
            // 
            splitContainer1.Panel1.Controls.Add(label2221);
            splitContainer1.Panel1.Controls.Add(btnAddToCart);
            splitContainer1.Panel1.Controls.Add(nudPosQty);
            splitContainer1.Panel1.Controls.Add(dgvPosProducts);
            // 
            // splitContainer1.Panel2
            // 
            splitContainer1.Panel2.Controls.Add(BTN321);
            splitContainer1.Panel2.Controls.Add(lblTax);
            splitContainer1.Panel2.Controls.Add(lblDiscount);
            splitContainer1.Panel2.Controls.Add(lblSubtotal);
            splitContainer1.Panel2.Controls.Add(comboPaymentMethod);
            splitContainer1.Panel2.Controls.Add(label1213213123);
            splitContainer1.Panel2.Controls.Add(txtCustId);
            splitContainer1.Panel2.Controls.Add(label3123123);
            splitContainer1.Panel2.Controls.Add(btnCheckout);
            splitContainer1.Panel2.Controls.Add(btnClearCart);
            splitContainer1.Panel2.Controls.Add(btnRemoveFromCart);
            splitContainer1.Panel2.Controls.Add(lblTotal);
            splitContainer1.Panel2.Controls.Add(dgvPosCart);
            splitContainer1.Size = new Size(691, 452);
            splitContainer1.SplitterDistance = 290;
            splitContainer1.TabIndex = 1;
            // 
            // label2221
            // 
            label2221.AutoSize = true;
            label2221.Font = new Font("Segoe UI", 11F);
            label2221.Location = new Point(54, 357);
            label2221.Name = "label2221";
            label2221.Size = new Size(65, 20);
            label2221.TabIndex = 3;
            label2221.Text = "Quantity";
            // 
            // btnAddToCart
            // 
            btnAddToCart.Location = new Point(54, 398);
            btnAddToCart.Name = "btnAddToCart";
            btnAddToCart.Size = new Size(174, 23);
            btnAddToCart.TabIndex = 2;
            btnAddToCart.Text = "Add to cart";
            btnAddToCart.UseVisualStyleBackColor = true;
            btnAddToCart.Click += btnAddToCart_Click;
            // 
            // nudPosQty
            // 
            nudPosQty.Font = new Font("Segoe UI", 11F);
            nudPosQty.Location = new Point(125, 354);
            nudPosQty.Name = "nudPosQty";
            nudPosQty.Size = new Size(103, 27);
            nudPosQty.TabIndex = 1;
            nudPosQty.Value = new decimal(new int[] { 1, 0, 0, 0 });
            // 
            // dgvPosProducts
            // 
            dgvPosProducts.AllowUserToAddRows = false;
            dgvPosProducts.AllowUserToDeleteRows = false;
            dgvPosProducts.AllowUserToResizeColumns = false;
            dgvPosProducts.AllowUserToResizeRows = false;
            dgvPosProducts.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dgvPosProducts.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dgvPosProducts.Dock = DockStyle.Top;
            dgvPosProducts.EditMode = DataGridViewEditMode.EditProgrammatically;
            dgvPosProducts.Location = new Point(0, 0);
            dgvPosProducts.MaximumSize = new Size(0, 500);
            dgvPosProducts.MinimumSize = new Size(0, 200);
            dgvPosProducts.Name = "dgvPosProducts";
            dgvPosProducts.RowHeadersVisible = false;
            dgvPosProducts.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            dgvPosProducts.Size = new Size(290, 323);
            dgvPosProducts.TabIndex = 0;
            // 
            // BTN321
            // 
            BTN321.Location = new Point(258, 217);
            BTN321.Name = "BTN321";
            BTN321.Size = new Size(75, 23);
            BTN321.TabIndex = 15;
            BTN321.Text = "Lookup";
            BTN321.UseVisualStyleBackColor = true;
            BTN321.Click += btnLookupCustomer_Click;
            // 
            // lblTax
            // 
            lblTax.AutoSize = true;
            lblTax.Font = new Font("Segoe UI", 15F);
            lblTax.Location = new Point(23, 353);
            lblTax.Name = "lblTax";
            lblTax.Size = new Size(48, 28);
            lblTax.TabIndex = 14;
            lblTax.Text = "Tax: ";
            // 
            // lblDiscount
            // 
            lblDiscount.AutoSize = true;
            lblDiscount.Font = new Font("Segoe UI", 15F);
            lblDiscount.Location = new Point(218, 295);
            lblDiscount.Name = "lblDiscount";
            lblDiscount.Size = new Size(93, 28);
            lblDiscount.TabIndex = 13;
            lblDiscount.Text = "Discount:";
            // 
            // lblSubtotal
            // 
            lblSubtotal.AutoSize = true;
            lblSubtotal.Font = new Font("Segoe UI", 15F);
            lblSubtotal.Location = new Point(17, 295);
            lblSubtotal.Name = "lblSubtotal";
            lblSubtotal.Size = new Size(96, 28);
            lblSubtotal.TabIndex = 12;
            lblSubtotal.Text = "Subtotal: ";
            // 
            // comboPaymentMethod
            // 
            comboPaymentMethod.Font = new Font("Segoe UI", 11F);
            comboPaymentMethod.FormattingEnabled = true;
            comboPaymentMethod.Items.AddRange(new object[] { "Cash", "Credit Card", "Banking" });
            comboPaymentMethod.Location = new Point(107, 250);
            comboPaymentMethod.Name = "comboPaymentMethod";
            comboPaymentMethod.Size = new Size(130, 28);
            comboPaymentMethod.TabIndex = 11;
            comboPaymentMethod.Text = "Cash";
            // 
            // label1213213123
            // 
            label1213213123.AutoSize = true;
            label1213213123.Font = new Font("Segoe UI", 11F);
            label1213213123.Location = new Point(33, 253);
            label1213213123.Name = "label1213213123";
            label1213213123.Size = new Size(68, 20);
            label1213213123.TabIndex = 10;
            label1213213123.Text = "Payment:";
            // 
            // txtCustId
            // 
            txtCustId.Font = new Font("Segoe UI", 11F);
            txtCustId.Location = new Point(107, 217);
            txtCustId.Name = "txtCustId";
            txtCustId.Size = new Size(130, 27);
            txtCustId.TabIndex = 9;
            // 
            // label3123123
            // 
            label3123123.AutoSize = true;
            label3123123.Font = new Font("Segoe UI", 11F);
            label3123123.Location = new Point(7, 220);
            label3123123.Name = "label3123123";
            label3123123.Size = new Size(94, 20);
            label3123123.TabIndex = 8;
            label3123123.Text = "Customer ID:";
            // 
            // btnCheckout
            // 
            btnCheckout.Location = new Point(306, 398);
            btnCheckout.Name = "btnCheckout";
            btnCheckout.Size = new Size(75, 23);
            btnCheckout.TabIndex = 7;
            btnCheckout.Text = "Pay";
            btnCheckout.UseVisualStyleBackColor = true;
            // 
            // btnClearCart
            // 
            btnClearCart.Location = new Point(173, 398);
            btnClearCart.Name = "btnClearCart";
            btnClearCart.Size = new Size(75, 23);
            btnClearCart.TabIndex = 6;
            btnClearCart.Text = "Clear";
            btnClearCart.UseVisualStyleBackColor = true;
            // 
            // btnRemoveFromCart
            // 
            btnRemoveFromCart.Location = new Point(26, 398);
            btnRemoveFromCart.Name = "btnRemoveFromCart";
            btnRemoveFromCart.Size = new Size(75, 23);
            btnRemoveFromCart.TabIndex = 5;
            btnRemoveFromCart.Text = "Remove";
            btnRemoveFromCart.UseVisualStyleBackColor = true;
            // 
            // lblTotal
            // 
            lblTotal.AutoSize = true;
            lblTotal.Font = new Font("Segoe UI", 15F);
            lblTotal.Location = new Point(218, 350);
            lblTotal.Name = "lblTotal";
            lblTotal.Size = new Size(63, 28);
            lblTotal.TabIndex = 4;
            lblTotal.Text = "Total: ";
            // 
            // dgvPosCart
            // 
            dgvPosCart.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
            dgvPosCart.CausesValidation = false;
            dgvPosCart.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dgvPosCart.Dock = DockStyle.Top;
            dgvPosCart.Location = new Point(0, 0);
            dgvPosCart.Name = "dgvPosCart";
            dgvPosCart.RowHeadersVisible = false;
            dgvPosCart.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
            dgvPosCart.Size = new Size(397, 208);
            dgvPosCart.TabIndex = 0;
            // 
            // panel1
            // 
            panel1.Controls.Add(label2);
            panel1.Controls.Add(lblCartCount);
            panel1.Controls.Add(btnPosSearch);
            panel1.Controls.Add(txtPosSearch);
            panel1.Dock = DockStyle.Top;
            panel1.Location = new Point(3, 3);
            panel1.MaximumSize = new Size(0, 45);
            panel1.Name = "panel1";
            panel1.Size = new Size(691, 45);
            panel1.TabIndex = 0;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 11F);
            label2.Location = new Point(3, 12);
            label2.Name = "label2";
            label2.Size = new Size(56, 20);
            label2.TabIndex = 4;
            label2.Text = "Search:";
            // 
            // lblCartCount
            // 
            lblCartCount.AutoSize = true;
            lblCartCount.Font = new Font("Segoe UI", 11.25F, FontStyle.Bold, GraphicsUnit.Point, 0);
            lblCartCount.Location = new Point(588, 12);
            lblCartCount.Name = "lblCartCount";
            lblCartCount.Size = new Size(98, 20);
            lblCartCount.TabIndex = 3;
            lblCartCount.Text = "Cart: 0 items";
            // 
            // btnPosSearch
            // 
            btnPosSearch.Location = new Point(234, 12);
            btnPosSearch.Name = "btnPosSearch";
            btnPosSearch.Size = new Size(75, 23);
            btnPosSearch.TabIndex = 2;
            btnPosSearch.Text = "Search";
            btnPosSearch.UseVisualStyleBackColor = true;
            // 
            // txtPosSearch
            // 
            txtPosSearch.Font = new Font("Segoe UI", 11F);
            txtPosSearch.Location = new Point(67, 9);
            txtPosSearch.Name = "txtPosSearch";
            txtPosSearch.Size = new Size(161, 27);
            txtPosSearch.TabIndex = 1;
            // 
            // tabControlMain
            // 
            tabControlMain.Controls.Add(POS);
            tabControlMain.Controls.Add(Products);
            tabControlMain.Controls.Add(Customer);
            tabControlMain.Controls.Add(Employee);
            tabControlMain.Controls.Add(tabPageInvoice);
            tabControlMain.Dock = DockStyle.Fill;
            tabControlMain.Location = new Point(0, 0);
            tabControlMain.Name = "tabControlMain";
            tabControlMain.SelectedIndex = 0;
            tabControlMain.Size = new Size(705, 531);
            tabControlMain.TabIndex = 0;
            // 
            // MainForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(705, 531);
            Controls.Add(tabControlMain);
            Name = "MainForm";
            Text = "Supermarket Manager";
            ((System.ComponentModel.ISupportInitialize)productBindingSource).EndInit();
            tabPageInvoice.ResumeLayout(false);
            splitContainer2.Panel1.ResumeLayout(false);
            splitContainer2.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)splitContainer2).EndInit();
            splitContainer2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)dgvInvoices).EndInit();
            ((System.ComponentModel.ISupportInitialize)dgvInvoiceItems).EndInit();
            panel4.ResumeLayout(false);
            panel4.PerformLayout();
            Employee.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)dgvEmployees).EndInit();
            panel3.ResumeLayout(false);
            panel3.PerformLayout();
            Customer.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)dgvCustomers).EndInit();
            panel2.ResumeLayout(false);
            panel2.PerformLayout();
            Products.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)dgvProducts).EndInit();
            panelProductsToolbar.ResumeLayout(false);
            panelProductsToolbar.PerformLayout();
            POS.ResumeLayout(false);
            splitContainer1.Panel1.ResumeLayout(false);
            splitContainer1.Panel1.PerformLayout();
            splitContainer1.Panel2.ResumeLayout(false);
            splitContainer1.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)splitContainer1).EndInit();
            splitContainer1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)nudPosQty).EndInit();
            ((System.ComponentModel.ISupportInitialize)dgvPosProducts).EndInit();
            ((System.ComponentModel.ISupportInitialize)dgvPosCart).EndInit();
            panel1.ResumeLayout(false);
            panel1.PerformLayout();
            tabControlMain.ResumeLayout(false);
            ResumeLayout(false);
        }

        #endregion
        private TabPage Employees;
        private DataGridViewTextBoxColumn colProdName;
        private DataGridViewTextBoxColumn colProdPrice;
        private DataGridViewTextBoxColumn colProdQty;
        private BindingSource productBindingSource;
        private TabPage tabPageInvoice;
        private Panel panel4;
        private Button btnSearchInvoice;
        private TextBox txtSearchInvoice;
        private Button btnRefreshInvoice;
        private TabPage Employee;
        private DataGridView dgvEmployees;
        private Panel panel3;
        private Button btnSearchEmployees;
        private TextBox txtSearchEmployees;
        private Button btnDeleteEmployee;
        private Button btnRefreshEmployees;
        private Button btnLoadEmployees;
        private TabPage Customer;
        private DataGridView dgvCustomers;
        private Panel panel2;
        private Button btnSearchCustomers;
        private TextBox txtSearchCustomers;
        private Button btnDeleteCustomer;
        private Button btnRefreshCustomers;
        private Button btnLoadCustomers;
        private TabPage Products;
        private DataGridView dgvProducts;
        private Panel panelProductsToolbar;
        private Button btnSearchProducts;
        private TextBox txtSearchProducts;
        private Button btnDeleteProduct;
        private Button btnRefreshProducts;
        private Button btnLoadProducts;
        private TabPage POS;
        private SplitContainer splitContainer1;
        private Label label2221;
        private Button btnAddToCart;
        private NumericUpDown nudPosQty;
        private DataGridView dgvPosProducts;
        private Button BTN321;
        private Label lblTax;
        private Label lblDiscount;
        private Label lblSubtotal;
        private ComboBox comboPaymentMethod;
        private Label label1213213123;
        private TextBox txtCustId;
        private Label label3123123;
        private Button btnCheckout;
        private Button btnClearCart;
        private Button btnRemoveFromCart;
        private Label lblTotal;
        private DataGridView dgvPosCart;
        private Panel panel1;
        private Label label2;
        private Label lblCartCount;
        private Button btnPosSearch;
        private TextBox txtPosSearch;
        private TabControl tabControlMain;
        private SplitContainer splitContainer2;
        private DataGridView dgvInvoices;
        private DataGridView dgvInvoiceItems;
    }
}
