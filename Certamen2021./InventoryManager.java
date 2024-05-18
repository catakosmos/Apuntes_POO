import java.io.FileNotFoundException;
import java.util.ArrayList;

public class InventoryManager {
    public static void main(String[] args) {
        try {
            FileManager fileManager = new FileManager("data_example_csv.csv");
            ArrayList<String> rowData = fileManager.getRowData();
            for (String data : rowData) {
                System.out.println(data);
            }
            ActionFinderStrategy.performAction(args, rowData);
        } catch (FileNotFoundException e) {
            System.out.println("Ocurrio un error al procesar el archivo.");
            e.printStackTrace();
        } catch (ArgumentInputException e) {
            System.out.println(e.getMessage());
        }
    }
}
