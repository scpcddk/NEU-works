import java.util.Iterator;

public class PlainTextSalesFormatter implements SalesFormatter {
    private static PlainTextSalesFormatter singletonInstance;

    private PlainTextSalesFormatter() {

    }

    public static PlainTextSalesFormatter getSingletonInstance() {
        if(singletonInstance == null) {
            singletonInstance = new PlainTextSalesFormatter();
        }
        return singletonInstance;
    }

    public String formatSales(Sales sales) {
        StringBuilder sb = new StringBuilder();
        Iterator<Order> orders = sales.iterator();
        int orderNumber = 1;

        while(orders.hasNext()) {
            Order order = orders.next();

            sb.append("------------------------\n");
            sb.append("Order " + orderNumber + "\n");

            Iterator<OrderItem> items = order.iterator();
            while(items.hasNext()) {
                OrderItem item = items.next();
                Product product = item.getProduct();

                sb.append(item.getQuantity() + " " + product.getCode() + "  " + product.getPrice() + "\n");
            }

            sb.append("\nTotal: " + order.getTotalCost() + "\n");

            orderNumber++;
        }

        return sb.toString();
    }

}
