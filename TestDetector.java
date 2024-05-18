import javafx.geometry.Point2D;
import javafx.scene.shape.Circle;
public class FlyDetector extends Circle {        // Clase FlyDetector
 public FlyDetector(int r){
 super(r);
 }
 public void checkDetection (Point2D fly) {
 if (contains(fly))
 System.out.println("Detectado");
 }
}


import javafx.geometry.Point2D;
import java.util.Scanner;
public class TestDetector {                // Programa principal
 public void executeUserInteraction (Scanner in, Point2D fly, FlyDetector flyDetector){
 char movement;
 boolean done =false;
 while (!done) {
 movement = in.next().charAt(0);
 switch (movement) {                      // Mosca simulada movida con WASD
 case 'w': fly = fly.add(0, 5);           //  W: x, y+5
 break;
 case 'a': fly = fly.add(-5, 0);          //  A: x-5, y
 break;
 case 's': fly = fly.add(5, 0);           //  S: x+5, y
 break;
 case 'z': fly = fly.add(0, -5);          //  D: x, y-5
 break;
 case 'x': done=true;                     // X : el programa termina
 }
 flyDetector.checkDetection(fly);
 }
 }
 public static void main(String [] args) {    // Parámetros para la ejecución del programa
 int mx = Integer.parseInt(args[0]);          // <mx>: posicion inicial en x
 int my = Integer.parseInt(args[1]);          // <my>: posicion inicial en y
 Point2D fly = new Point2D(mx, my);           // Detector ubicado en el origen
 int range = Integer.parseInt(args[2]);       // <range>: rango de detección
 FlyDetector flyDetector = new FlyDetector(range);  
 TestDetector td = new TestDetector();
 td.executeUserInteraction(new Scanner(System.in), fly, flyDetector);
 }
}
