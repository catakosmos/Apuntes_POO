import java.util.ArrayList;

public class ActionFinderStrategy {
    public static void performAction (String[] args, ArrayList<String> rowData) throws ArgumentInputException {
        try {
            if (args[0].equals("-s")) {
                System.out.println("Buscar");
                System.out.println(args[1]);
                System.out.println(args[2]);
            } else if (args[0].equals("-o")) {
                System.out.println("Ordenar");
            }
        } catch (ArrayIndexOutOfBoundsException e) {
            throw new ArgumentInputException("Debe ingresar argumentos al programa: -s -> Buscar, -brand -> Por marca, -o -> Ordenar, -desc -> De mayor a menor");
        }
    }
}
