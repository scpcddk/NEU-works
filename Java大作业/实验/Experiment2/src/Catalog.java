import java.util.Iterator;
import java.util.ArrayList;

public class Catalog implements Iterable<Product> {
    private ArrayList<Product> products;
    public Catalog() {
        products = new ArrayList<Product>();
    }
    public void addProduct(Product product) {
        products.add(product);
    }
    public Iterator<Product> iterator() {
        return products.iterator();
    }
    public Product getProduct(String code) {
        for (Product product : products) {
            if (product.getCode().equals(code)) {
                return product;
            }
        }
        return null;
    }

    public int getNumberOfProducts() {
        return products.size();
    }
}
