// interfaz funcional : permite usar expresiones lambda y debe contener 1 SOLO METODO SIN IMPLEMENTAR

// @FunctionalInterface    -> esta linea es opcional
public interface Interfaz{

    void metodo(String stringVar);  // metodo sin implementar
    //String metodo2();             -> si se descomenta lanzara error ya que dejaria de ser una interfaz funcional


    // metodos que si puede implementar:
    default void metodoDefault(){   // opcional
        System.out.println("metodo por defecto en la interfaz");    
    }

    static void metodoEstatico(){   // opcional
        // metodo de la interfaz, similar a 'static' para clases
        // se debe llamar: Interfaz.metodoEstatico()
    }
}
