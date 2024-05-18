// Clase main
public class Main {
 public static void main(String[] args) {
 TickTackToe4 t = new TickTackToe4();    // Crea el tictactoe en una instancia
 t.play();                               // Llama a play()
 }
}
// Clase Casilla
public class Casilla {
 public Casilla(){user=0;}      // Puede ser ocupada por uno de los 2 user o vacia
 public int getUser() {         // Retorna quien está usando la casilla
 return user;
 }
 public void setUser(int user) {  // Establece el valor del usuario usando la casilla
 this.user = user;
 }
 private int user;
}

// Clase TickTackToe 
import java.util.Scanner;
public class TickTackToe4 {
 public TickTackToe4(){
 currentPlayer = 1;              // Inicializa con el jugador 1
 winner = 0;
 c = new Casilla[4][4];          // Inicializa el tablero 4*4
 for (int i = 0; i < 4; i++)
 for (int j = 0; j < 4; j++)
 c[i][j] = new Casilla();
 }
 public void play(){
 while(!termino()){              // En bucle hasta que se termine
 escogerCasilla();               // Jugador actual escoge la casilla
 imprimirTablero();
 if(currentPlayer==1) currentPlayer=2; else currentPlayer=1; // Paso de turno
 }
 imprimirMEnsajeFinal();
 }
 void imprimirTablero(){            // Imprimir escenario actual fila por fila  
 for(int row=0; row < 4; row++ ){    // Recorrido con doble for el array bidimensional
 for(int col=0; col<4; col++)
 System.out.print( c[row][col].getUser() );  // Imprimir el usuario de la casilla
 System.out.print("\n");
 }
 }
 private void escogerCasilla() {      // Solicita al jugador actual escoger la casilla
 Scanner s = new Scanner(System.in);
 System.out.println("Jugador " + String.valueOf(currentPlayer));
 System.out.println("fila:");
 String row = s.nextLine();
 System.out.println("col:");
 String col = s.nextLine();
 c[Integer.parseInt(row)-1][Integer.parseInt(col)-1].setUser(currentPlayer);
 }
 public boolean termino(){      
 for(int row=0; row < 4; row++ ) {
 int user_to_test = c[row][0].getUser();    // Verifica si hay jugador en alguna fila o columna
 if(user_to_test == 0)break;
 if(c[row][0].getUser() == c[row][1].getUser() &&
 c[row][1].getUser() == c[row][2].getUser() &&
 c[row][2].getUser() == c[row][3].getUser()){
 winner = user_to_test;
 return true;
 }
 }
 for(int col=0; col < 4; col++ ){
 int user_to_test = c[0][col].getUser();
 if(user_to_test == 0)break;
 if(c[0][col].getUser() == c[1][col].getUser() &&
 c[1][col].getUser() == c[2][col].getUser() &&
 c[2][col].getUser() == c[3][col].getUser()){
 winner = user_to_test;
 return true;
 }
 }
 int totalCasillasUsed = 0;
 for(int row=0; row < 4; row++ )
 for(int col=0; col<4; col++)
 if(c[row][col].getUser()!=0)totalCasillasUsed++;
 if(totalCasillasUsed==16) return true;
 return false;
 }
 void imprimirMEnsajeFinal(){
 if(winner == 1){
 System.out.println("Felicidades jugador 1");
 }else if(winner==2){
 System.out.println("Felicidades jugador 2");
 }
 else{System.out.println("Empate");}
 }
 private Casilla[][] c;
 private int currentPlayer;
 private int winner;
}
