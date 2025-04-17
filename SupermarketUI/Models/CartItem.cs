namespace SupermarketUI.Models
{
    public class CartItem
    {
        public Product Product { get; }
        public int Quantity { get; set; }
        public float Subtotal => Product.Price * Quantity;
        public string ProductName => Product.Name;
        public CartItem(Product p, int qty)
        {
            Product = p;
            Quantity = qty;
        }
    }
}