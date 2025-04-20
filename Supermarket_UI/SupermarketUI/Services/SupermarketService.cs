using SupermarketUI.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Microsoft.VisualBasic.FileIO;


namespace SupermarketUI.Services
{
    public class SupermarketService
    {
        private readonly List<Product> _products = new();
        private readonly List<Customer> _customers = new();
        private readonly List<Employee> _employees = new();
        private readonly List<Bill> _bills = new();
        public Cart CurrentCart { get; } = new();

        private readonly string _prodFile = "data_product.csv";
        private readonly string _custFile = "data_customer.csv";
        private readonly string _empFile = "data_employee.csv";
        private readonly string _billFile = "data_bill.csv";

        public SupermarketService()
        {
            LoadCsv();
        }

        // ────── CSV I/O ───────
        private void LoadCsv()
        {
            if (File.Exists(_prodFile))
            {
                var lines = File.ReadAllLines(_prodFile)
                                   .Where(l => !string.IsNullOrWhiteSpace(l))
                                   .ToArray();

                // Skip the header row:
                foreach (var line in lines.Skip(1))
                {
                    var f = line.Split(',');
                    _products.Add(new Product
                    {
                        Id = f[0],
                        Name = f[1],
                        Price = float.Parse(f[2]),
                        Quantity = int.Parse(f[3])
                    });
                }
            }
            if (File.Exists(_custFile))
            {
                // Read all non‑empty lines, then skip the first (the header)
                var lines = File.ReadAllLines(_custFile)
                                .Where(l => !string.IsNullOrWhiteSpace(l))
                                .ToArray();

                foreach (var line in lines.Skip(1))
                {
                    var f = line.Split(',');
                    _customers.Add(new Customer
                    {
                        Id = f[0],
                        Name = f[1],
                        Phone = f[2],
                        MemberType = f[3],
                        LoyaltyPoints = int.Parse(f[4])
                    });
                }
            }
            if (File.Exists(_empFile))
            {
                // read all non-empty lines, skip header
                var lines = File.ReadAllLines(_empFile)
                                .Where(l => !string.IsNullOrWhiteSpace(l))
                                .ToArray();

                foreach (var line in lines.Skip(1))
                {
                    var f = line.Split(',');
                    _employees.Add(new Employee
                    {
                        Id = f[0],
                        Name = f[1],
                        Phone = f[2],
                        Position = f[3],
                        Salary = double.Parse(f[4]),
                        DateHired = DateTime.Parse(f[5])
                    });
                }
            }
            if (File.Exists(_billFile))
            {
                // Use TextFieldParser to handle commas and quoted Items
                using var parser = new TextFieldParser(_billFile)
                {
                    TextFieldType = FieldType.Delimited,
                    HasFieldsEnclosedInQuotes = true
                };
                parser.SetDelimiters(",");

                // Skip header
                if (!parser.EndOfData) parser.ReadFields();

                while (!parser.EndOfData)
                {
                    var f = parser.ReadFields();
                    // f[0]=InvoiceId, f[1]=CustomerId, f[2]=Date,
                    // f[3]=PaymentMethod, f[4]=Items (quoted), f[5]=Discount, f[6]=Tax, f[7]=Total

                    var bill = new Bill
                    {
                        InvoiceId = f[0],
                        CustomerId = f[1],
                        EmployeeId = "",              // you removed it
                        Date = DateTime.Parse(f[2]),
                        PaymentMethod = f[3]
                    };

                    // Items come in as e.g. "P001,2|P003,1"
                    var itemsField = f[4].Trim('"');
                    foreach (var part in itemsField.Split('|'))
                    {
                        var p = part.Split(',');
                        if (p.Length == 2)
                        {
                            var prod = _products.FirstOrDefault(x => x.Id == p[0]);
                            if (prod != null)
                                bill.Items.Add(new CartItem(prod, int.Parse(p[1])));
                        }
                    }

                    // Discount, Tax, Total
                    if (float.TryParse(f[5], out var d)) bill.Discount = d;
                    if (float.TryParse(f[6], out var t)) bill.Tax = t;

                    _bills.Add(bill);
                }
            }
        }

          private void SaveCsv()
    {
        // PRODUCTS: write header + data
        var prodLines = new List<string>();
        prodLines.Add("Id,Name,Price,Quantity");
        prodLines.AddRange(_products.Select(p => 
            $"{p.Id},{p.Name},{p.Price},{p.Quantity}"
        ));
        File.WriteAllLines(_prodFile, prodLines);

        // CUSTOMERS: likewise
        var custLines = new List<string>();
        custLines.Add("Id,Name,Phone,MemberType,LoyaltyPoints");
        custLines.AddRange(_customers.Select(c =>
            $"{c.Id},{c.Name},{c.Phone},{c.MemberType},{c.LoyaltyPoints}"
        ));
        File.WriteAllLines(_custFile, custLines);

        // EMPLOYEES:
        var empLines = new List<string> {
            "Id,Name,Phone,Position,Salary,DateHired"
        };
        empLines.AddRange(_employees.Select(e =>
            $"{e.Id},{e.Name},{e.Phone},{e.Position},{e.Salary},{e.DateHired:O}"
        ));
        File.WriteAllLines(_empFile, empLines);

            var billLines = new List<string> {
    "InvoiceId,CustomerId,Date,PaymentMethod,Items,Discount,Tax,Total"
};

            billLines.AddRange(_bills.Select(b =>
                b.InvoiceId + "," +
                b.CustomerId + "," +
                // <-- friendly date format here:
                b.Date.ToString("yyyy-MM-dd HH:mm") + "," +
                b.PaymentMethod + "," +
                "\"" + string.Join("|", b.Items.Select(i => $"{i.Product.Id},{i.Quantity}")) + "\"," +
                b.Discount.ToString("F2") + "," +
                b.Tax.ToString("F2") + "," +
                b.Total.ToString("F2")
            ));

            File.WriteAllLines(_billFile, billLines);
        }

        // ────── Product Ops ───────
        public List<Product> GetProducts() => _products;
        public void AddProduct(Product p) { _products.Add(p); SaveCsv(); }
        public void UpdateProduct(Product p)
        {
            var ex = _products.First(x => x.Id == p.Id);
            ex.Name = p.Name; ex.Price = p.Price; ex.Quantity = p.Quantity;
            SaveCsv();
        }
        public void DeleteProduct(string id)
        {
            _products.RemoveAll(p => p.Id == id);
            SaveCsv();
        }
        public Product FindProductById(string id)
            => _products.FirstOrDefault(p => p.Id == id);
        public List<Product> SearchProducts(string name)
            => _products.Where(p => p.Name.Contains(name, StringComparison.OrdinalIgnoreCase)).ToList();
        public void SortProductsBy(string field)
        {
            switch (field)
            {
                case "Name": _products.Sort((a, b) => a.Name.CompareTo(b.Name)); break;
                case "Price": _products.Sort((a, b) => a.Price.CompareTo(b.Price)); break;
                case "Qty": _products.Sort((a, b) => a.Quantity.CompareTo(b.Quantity)); break;
            }
        }

        // ────── Customer Ops ───────
        public List<Customer> GetCustomers() => _customers;
        public void AddCustomer(Customer c) { _customers.Add(c); SaveCsv(); }
        public void UpdateCustomer(Customer c)
        {
            var ex = _customers.First(x => x.Id == c.Id);
            ex.Name = c.Name; ex.Phone = c.Phone;
            ex.MemberType = c.MemberType; ex.LoyaltyPoints = c.LoyaltyPoints;
            SaveCsv();
        }
        public void DeleteCustomer(string id)
        {
            _customers.RemoveAll(c => c.Id == id);
            SaveCsv();
        }
        public Customer FindCustomerById(string id)
            => _customers.FirstOrDefault(c => c.Id == id);
        public List<Customer> SearchCustomers(string term)
            => _customers.Where(c => c.Name.Contains(term, StringComparison.OrdinalIgnoreCase)).ToList();

        // ────── Employee Ops ───────
        public List<Employee> GetEmployees() => _employees;
        public void AddEmployee(Employee e) { _employees.Add(e); SaveCsv(); }
        public void UpdateEmployee(Employee e)
        {
            var ex = _employees.First(x => x.Id == e.Id);
            ex.Name = e.Name; ex.Phone = e.Phone;
            ex.Position = e.Position; ex.Salary = e.Salary;
            ex.DateHired = e.DateHired;
            SaveCsv();
        }
        public void DeleteEmployee(string id)
        {
            _employees.RemoveAll(e => e.Id == id);
            SaveCsv();
        }
        public Employee FindEmployeeById(string id)
            => _employees.FirstOrDefault(e => e.Id == id);

        // ────── Cart & Billing ───────
        public bool AddToCart(string prodId, int qty)
        {
            var p = FindProductById(prodId);
            if (p == null || p.Quantity < qty) return false;

            // 1) add to cart
            CurrentCart.AddItem(p, qty);

            // 2) immediately reduce stock
            p.Quantity -= qty;

            return true;
        }
        public bool RemoveFromCart(string prodId)
        {
            // Find the CartItem in the cart
            var item = CurrentCart.Items.FirstOrDefault(i => i.Product.Id == prodId);
            if (item == null) return false;

            // Restore stock
            var prod = FindProductById(prodId);
            if (prod != null)
            {
                prod.Quantity += item.Quantity;
            }

            // Remove from cart
            CurrentCart.RemoveItem(prodId);


            return true;
        }
        public void ClearCart()
        {
            // For each item in the cart, put its quantity back
            foreach (var item in CurrentCart.Items)
            {
                var prod = FindProductById(item.Product.Id);
                if (prod != null)
                    prod.Quantity += item.Quantity;
            }

            // Empty the cart
            CurrentCart.Clear();


        }
        public Bill Checkout(
    string customerId,
    string employeeId,
    float discountRate,
    float taxRate,
    string payment)
        {
            // Build the bill skeleton
            var bill = new Bill
            {
                InvoiceId = "INV" + (_bills.Count + 1),
                CustomerId = customerId,
                EmployeeId = employeeId,
                Date = DateTime.Now,
                PaymentMethod = payment
            };
            // Copy the cart items
            bill.Items.AddRange(CurrentCart.Items);

            // Use the bill’s Subtotal property as our base
            float sub = bill.Subtotal;

            // Compute discount and tax
            bill.Discount = sub * discountRate;
            bill.Tax = (sub - bill.Discount) * taxRate;

            // Persist and clear
            _bills.Add(bill);
            SaveCsv();
            CurrentCart.Clear();

            return bill;
        }
        public List<Bill> GetBills() => _bills;
        public List<Bill> SearchBillsByCustomer(string custId)
            => _bills.Where(b => b.CustomerId == custId).ToList();
        public Bill FindBill(string invoiceId)
            => _bills.FirstOrDefault(b => b.InvoiceId == invoiceId);

        // ────── Reporting & Sorting ───────
        public List<Bill> GetBillsByDateRange(DateTime from, DateTime to)
            => _bills.Where(b => b.Date >= from && b.Date <= to).ToList();
        public List<Product> TopSellingProducts(int topN)
            => _bills
               .SelectMany(b => b.Items)
               .GroupBy(i => i.Product.Id)
               .Select(g => new { Id = g.Key, Sold = g.Sum(i => i.Quantity) })
               .OrderByDescending(x => x.Sold)
               .Take(topN)
               .Select(x => FindProductById(x.Id))
               .ToList();
        public void ReloadData()
        {
            _products.Clear();
            _customers.Clear();
            _employees.Clear();
            _bills.Clear();
            LoadCsv();
        }
    }

}
