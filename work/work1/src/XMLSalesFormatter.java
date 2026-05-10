import java.util.Iterator;

public class XMLSalesFormatter implements SalesFormatter {
    private static XMLSalesFormatter singletonInstance;
    private XMLSalesFormatter() {

    }

    public static XMLSalesFormatter getSingletonInstance() {
        if(singletonInstance == null) {
            singletonInstance = new XMLSalesFormatter();
        }
        return singletonInstance;
    }

    public String formatSales(Sales sales) {
        StringBuilder sb = new StringBuilder();
        sb.append("<xml>\\n");

        Iterator<Order> orders = sales.iterator();
        while(orders.hasNext()) {
            Order order = orders.next();
            sb.append("  <Order total=\"").append(order.getTotalCost()).append("\">\n");

            Iterator<OrderItem> items = order.iterator();
            while(items.hasNext()) {
                OrderItem item = items.next();
                Product product = item.getProduct();

                sb.append("    <OrderItem quantity=\"")
                        .append(item.getQuantity())
                        .append("\" price=\"")
                        .append(product.getPrice())
                        .append("\">")
                        .append(product.getCode())
                        .append("</OrderItem>\n");

            }
            sb.append("  </Order>\n");
        }
        sb.append("</Sales>\n");
        return sb.toString();
    }
}
