import java.util.ArrayList;
import java.util.List;      // librerias opcionales para el ejemplo 4

public class LambdaFunctionExample {
    public static void main(String[] args) {

        // Ejemplo 1

        // se instancia con la interfaz que implementa el metodo
        // argumento generico, pueden reemplazar "cualquierString" por cualquier otro nombre
        Interfaz interfaz = (cualquierString)->{
            System.out.println("Hola me llamo " + cualquierString);
        };

        interfaz= (s)->System.out.println("expresión lambda con parametro " + s); // una sola linea no necesita corchetes

        // Ejemplo 2

        Interfaz2 interfaz2 = (a,b)->{
            float resultado = a + b;
            return resultado;
        };

        // Ejemplo 3

        Interfaz3 interfaz3 = ()->{
            int n1=10, n2=20;
            boolean b = n1<n2;
            return b;
        };
        

        // output -----------------------------------------------

        String nombre = "Juan";
        float num1 = 19;
        float num2 = 31;
        boolean numBoolean;

        interfaz.metodo(nombre);                // instancia Ejemplo 1
        interfaz2.sumador(num1, num2);          // instancia Ejemplo 2
        numBoolean = interfaz3.metodoBool();    // instancia Ejemplo 3
        
        System.out.println(numBoolean); // output: true




        // Variable local: se declara dentro de un bloque de código, puede ser un método o un bloque simplemente
        {
            String variable_Local = "variable local";
            System.out.println(variable_Local);
        }
        // System.out.println(variable_Local);   -> incorrecto ya que solo es accesible dentro del bloque


        // motivacion
        // Ejemplo 4 (opcional)
        List<String> arrayDeString = new ArrayList<>(); // instancia interfaz List<> (Java Collections)

        /* 
        'arrayDeString' es una Estructura Dinámica, ya que puede 
        aumentar o disminuir su tamaño en tiempo de ejecución

        por ejemplo:
        int [] array = new int[5];
        sería una Estructura Estática ya que se define con un tamaño fijo al momento de su creación
        */
        
        arrayDeString.add("Hola "); // añadimos elementos
        arrayDeString.add("Mundo");

        arrayDeString.forEach(System.out::println);  // bucle for con referencia al metodo(::) println
    }
}
