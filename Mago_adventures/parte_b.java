// ...modificando el archivo Juego.java
// Excepción
int accion;
try{ // Captura excepción
accion = s.nextInt();
// Maneja excepción
}catch(InputMismatchException e1){
// accion con valor -1
accion = -1;// Retorna 1
}
