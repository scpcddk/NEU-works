import java.util.ArrayList;
import java.util.Iterator;

public class Order implements Iterable<OrderItem>{
    private ArrayList<OrderItem> items;
    public Order() {
        items = new ArrayList<OrderItem>();
    }
    public void addItem(OrderItem item) {
        items.add(item);
    }

    public void removeItem(OrderItem item){
        items.remove(item);
    }

    public Iterator<OrderItem> iterator() {
        return items.iterator();
    }

    public OrderItem getItem(Product product) {
        for(OrderItem item : items) {
            if(item.getProduct() == product) {
                return item;
            }
        }
        return null;
    }


    public int getNumberOfItems() {
        return items.size();
    }
    public double getTotalCost() {
        double total = 0.0;
        for(OrderItem item : items) {
            total += item.getValue();
        }
        return total;
    }
}
