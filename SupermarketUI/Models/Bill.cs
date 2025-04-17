using System;
using System.Collections.Generic;
using System.Linq;

namespace SupermarketUI.Models
{
    public class Bill
    {
        public string InvoiceId { get; set; }
        public string CustomerId { get; set; }
        public string EmployeeId { get; set; }
        public List<CartItem> Items { get; set; } = new List<CartItem>();
        public float Subtotal => Items.Sum(i => i.Subtotal);
        public float Discount { get; set; }
        public float Tax { get; set; }
        public float Total => Subtotal - Discount + Tax;
        public DateTime Date { get; set; }
        public string PaymentMethod { get; set; }
    }
}
