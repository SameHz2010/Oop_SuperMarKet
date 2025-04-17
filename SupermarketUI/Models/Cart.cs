using System.Collections.Generic;
using System.Linq;

namespace SupermarketUI.Models
{
    public class Cart
    {
        public string CustomerId { get; set; }
        private readonly List<CartItem> _items = new List<CartItem>();
        public IReadOnlyList<CartItem> Items => _items;

        public bool AddItem(Product p, int qty)
        {
            if (p.Quantity < qty) return false;
            var existing = _items.FirstOrDefault(i => i.Product.Id == p.Id);
            if (existing != null) existing.Quantity += qty;
            else _items.Add(new CartItem(p, qty));
            return true;
        }

        public bool RemoveItem(string productId)
        {
            var it = _items.FirstOrDefault(i => i.Product.Id == productId);
            if (it == null) return false;
            _items.Remove(it);
            return true;
        }

        public float Total => _items.Sum(i => i.Subtotal);
        public void Clear() => _items.Clear();
        public bool IsEmpty => !_items.Any();
    }
}
