using System;

namespace SupermarketUI.Models
{
    public class Product
    {
        public string Id { get; set; }
        public string Name { get; set; }
        public float Price { get; set; }
        public int Quantity { get; set; }

        public bool IsAvailable => Quantity > 0;

        public override string ToString()
            => $"{Name} ({Id}) – ${Price} × {Quantity}";
    }
}