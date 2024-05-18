Escriba el comando completo necesario para compilar TestDetector.java (pregunta b a) y el comando necesario para compilar JavaFxDetector.java.
* Comando para compilar TestDetector.java:
    ```html
    $javac TestDetector.java
    ```

* Comando para compilar JavaFxDetector.java:
```html
$ javac --module-path <path/to/javafx-sdk-17.0.2/lib> --add-modules javafx.controls JavaFxDetector.java
   ```
En < path/to/javafx-sdk-17.0.2/lib> reemplazar por la ruta completa donde está el directorio lib donde
JavaFX fue ubicado.
