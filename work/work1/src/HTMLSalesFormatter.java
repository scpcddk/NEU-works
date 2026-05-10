import java.util.Iterator;

public class HTMLSalesFormatter implements SalesFormatter {
    private static HTMLSalesFormatter singletonInstance;

    private HTMLSalesFormatter() {

    }

    public static HTMLSalesFormatter getSingletonInstance() {
        if(singletonInstance == null) {
            singletonInstance = new HTMLSalesFormatter();
        }
        return singletonInstance;
    }

    public String formatSales(Sales sales) {
        StringBuilder sb = new StringBuilder();

        sb.append("<html>\n"+"  <body>\\n"+"    <center><h2>Orders</h2></center>\\n");
        Iterator<Order> orders = sales.iterator();
        while(orders.hasNext()) {
            Order order = orders.next();

            sb.append("    <hr>\n");
            sb.append("    <h4>Total = ").append(order.getTotalCost()).append("</h4>\n");

            Iterator<OrderItem> items = order.iterator();
            while(items.hasNext()) {
                OrderItem item = items.next();
                Product product = item.getProduct();

                sb.append("      <p>\n")
                        .append("        <b>code:</b> ").append(product.getCode()).append("<br>\n")
                        .append("        <b>quantity:</b> ").append(item.getQuantity()).append("<br>\n")
                        .append("        <b>price:</b> ").append(product.getPrice()).append("\n")
                        .append("      </p>\n");
            }
        }
        sb.append("  </body>\n"+"</html>");
        return sb.toString();
    }
}
