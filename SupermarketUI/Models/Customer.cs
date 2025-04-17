namespace SupermarketUI.Models
{
    public class Customer
    {
        public string Id { get; set; }
        public string Name { get; set; }
        public string Phone { get; set; }
        public string MemberType { get; set; }
        public int LoyaltyPoints { get; set; }

        public float DiscountRate
            => MemberType == "Gold" ? 0.15f
             : MemberType == "Silver" ? 0.10f
             : 0.05f;
    }
}