import java.util.*;
import java.io.*;

public class FileCatalogLoader implements CatalogLoader {
    private Product readProduct(String line) throws DataFormatException {
        StringTokenizer tokenizer = new StringTokenizer(line, "_");
        if (tokenizer.countTokens() != 4) {
            throw new DataFormatException(line);
        }

        String prefix = tokenizer.nextToken(); // "Product"
        String code = tokenizer.nextToken();
        String description = tokenizer.nextToken();
        double price;
        try {
            price = Double.parseDouble(tokenizer.nextToken());
        } catch (NumberFormatException e) {
            throw new DataFormatException(line);
        }

        return new Product(code, description, price);
    }

    private Coffee readCoffee(String line) throws DataFormatException {
        StringTokenizer tokenizer = new StringTokenizer(line, "_");
        if (tokenizer.countTokens() != 10) {
            throw new DataFormatException(line);
        }

        String prefix = tokenizer.nextToken(); // "Coffee"
        String code = tokenizer.nextToken();
        String description = tokenizer.nextToken();
        double price;
        try {
            price = Double.parseDouble(tokenizer.nextToken());
        } catch (NumberFormatException e) {
            throw new DataFormatException(line);
        }
        String origin = tokenizer.nextToken();
        String roast = tokenizer.nextToken();
        String flavor = tokenizer.nextToken();
        String aroma = tokenizer.nextToken();
        String acidity = tokenizer.nextToken();
        String body = tokenizer.nextToken();

        return new Coffee(code, description, price, origin, roast, flavor, aroma, acidity, body);
    }

    private CoffeeBrewer readCoffeeBrewer(String line) throws DataFormatException {
        StringTokenizer tokenizer = new StringTokenizer(line, "_");
        if (tokenizer.countTokens() != 7) {
            throw new DataFormatException(line);
        }

        String prefix = tokenizer.nextToken(); // "Brewer"
        String code = tokenizer.nextToken();
        String description = tokenizer.nextToken();
        double price;
        try {
            price = Double.parseDouble(tokenizer.nextToken());
        } catch (NumberFormatException e) {
            throw new DataFormatException(line);
        }
        String model = tokenizer.nextToken();
        String waterSupply = tokenizer.nextToken();
        int numberOfCups;
        try {
            numberOfCups = Integer.parseInt(tokenizer.nextToken());
        } catch (NumberFormatException e) {
            throw new DataFormatException(line);
        }

        return new CoffeeBrewer(code, description, price, model, waterSupply, numberOfCups);
    }

    @Override
    public Catalog loadCatalog(String filename)
            throws FileNotFoundException, IOException, DataFormatException {
        Catalog catalog = new Catalog();
        BufferedReader reader = new BufferedReader(new FileReader(filename));
        String line;
        while ((line = reader.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) {
                continue;
            }
            if (line.startsWith("Product")) {
                catalog.addProduct(readProduct(line));
            } else if (line.startsWith("Coffee")) {
                catalog.addProduct(readCoffee(line));
            } else if (line.startsWith("Brewer")) {
                catalog.addProduct(readCoffeeBrewer(line));
            } else {
                // 无法识别的行类型 – 视为格式错误
                throw new DataFormatException(line);
            }
        }
        reader.close();
        return catalog;
    }
}