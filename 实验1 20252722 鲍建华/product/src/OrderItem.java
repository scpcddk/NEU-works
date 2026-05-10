public class OrderItem {
    private Product product;
    private int quantity;
    public OrderItem(Product initialProduct, int initialQuantity){
        product = initialProduct;
        quantity = initialQuantity;
    }
    public Product getProduct(){
        return product;
    }
    public int getQuantity(){
        return quantity;
    }
    public void setQuantity(int newQuantity){
        quantity = newQuantity;
    }
    public double getValue(){
        return product.getPrice() * quantity;
    }
    public String toString(){
        return quantity + " " + product.getCode() + " " + product.getPrice();
    }
}
