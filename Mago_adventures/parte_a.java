// ------ Personaje.java -------- //
public abstract class Personaje implements Metodos {
private String nombre;
protected int vida;
// Constructor: nombre y puntos de vida
public Personaje(String nombre, int vida){
this.nombre = nombre;      
this.vida = vida;
}
// Getters
public String getNombre(){
return this.nombre;
}
public int getVida(){
return this.vida;
}
// Definir atacar() como método abstracto
public abstract void atacar(Personaje objetivo);
// Métodos recibirDano() y estaVivo() 3pts
public void recibirDano(int cantidad){
this.vida -= cantidad;
}
public boolean estaVivo(){
return vida>0;
}
}

// Enemigo.java
public class Enemigo extends Personaje { // Hereda de la clase Personaje
private int fuerza;      // adicionalmente el atributo fuerza
// Constructor: nombre, vida Y FUERZA
public Enemigo(String nombre, int vida, int fuerza){
super(nombre, vida);    // Heredado
this.fuerza = fuerza;
}
// Constructor: 
public void atacar(Personaje objetivo){
objetivo.recibirDano(fuerza);
}
}


// Mago.java
import java.util.Random;
public class Mago extends Personaje{      // Hereda de la clase Personaje
private int poder;      // adicionalmente el atributo poder
// Constructor: nombre, vida Y PODER
public Mago(String nombre, int vida, int poder){
super(nombre, vida);
this.poder = poder;
}
// Método atacar() 
public void atacar(Personaje objetivo){
objetivo.recibirDano(poder);
}
// Metodo aumentarVida() 
public void aumentarVida(){
Random random = new Random();
super.vida += random.nextInt(5)+1; // Aumenta la vida de 1 a 5 (random)
}
}
