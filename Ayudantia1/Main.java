import javafx.animation.PathTransition;
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.Shape;
import javafx.stage.Stage;
import javafx.util.Duration;

public class Main extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    private PathTransition pathTransition;
    private Circle bigCircle;
    private Circle smallCircle;
    private Rectangle square;
    private boolean isSquareTouched = false;    // cambio de color

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Object Movement Example");

        // Punto central para el movimiento circular
        double startX = 200;
        double startY = 200;
        double size = 200;
        double radius = size / 2; // Radio del círculo pequeño

        // Crear un círculo grande que representa la trayectoria circular
        bigCircle = new Circle(startX, startY, radius);
        bigCircle.setFill(Color.TRANSPARENT);
        bigCircle.setStroke(Color.BLACK);

        // Calcular la posición inicial del círculo pequeño para que esté en el borde exterior de la circunferencia de recorrido
        double initialX = startX + radius;
        double initialY = startY;
        // Crear un círculo pequeño que se moverá en el recorrido
        smallCircle = new Circle(initialX, initialY, 10); // Radio arbitrario para el círculo pequeño

        // Crear un PathTransition para la animación del círculo pequeño
        pathTransition = new PathTransition();
        pathTransition.setDuration(Duration.seconds(2));
        pathTransition.setNode(smallCircle);
        pathTransition.setCycleCount(PathTransition.INDEFINITE);

        // Crear un Path para la trayectoria circular
        Circle circlePath = new Circle(startX, startY, radius); // Usar el mismo radio para el círculo pequeño y la trayectoria

        // Asignar el círculo grande como el camino de la animación
        pathTransition.setPath(circlePath);

        // Crear un cuadrado negro
        square = new Rectangle(50, 50, 50, 50);
        square.setFill(Color.BLACK);

        // Crear botones
        Button startStopButton = new Button("Start");
        startStopButton.setTranslateX(150);                 // Coordenadas x e y
        startStopButton.setTranslateY(350);
        startStopButton.setOnAction(event -> {              // definimos un evento para correr o detener la animación
            if (pathTransition.getStatus() == PathTransition.Status.RUNNING) {
                pathTransition.pause();
                startStopButton.setText("Start");
            } else {
                pathTransition.play();
                startStopButton.setText("Stop");
            }
        });

        // Boton para cambiar de color de forma aleatoria
        Button changeColorButton = new Button("Change Color");
        changeColorButton.setTranslateX(200);
        changeColorButton.setTranslateY(350);
        changeColorButton.setOnAction(event -> smallCircle.setFill(Color.color(Math.random(), Math.random(), Math.random())));

        // Crear un grupo para los elementos
        Group root = new Group();
        root.getChildren().addAll(bigCircle, smallCircle, square, startStopButton, changeColorButton);

        Scene scene = new Scene(root, 400, 400);

        // Manejar eventos de teclado para mover el cuadrado
        scene.setOnKeyPressed(e -> {
            switch (e.getCode()) {
                case W:
                    square.setY(square.getY() - 10);
                    break;
                case S:
                    square.setY(square.getY() + 10);
                    break;
                case A:
                    square.setX(square.getX() - 10);
                    break;
                case D:
                    square.setX(square.getX() + 10);
                    break;
                default:
                    break;
            }
        });

        // Verificar la colisión entre el cuadrado y el círculo pequeño en cada fotograma de la animación
        pathTransition.currentTimeProperty().addListener((obs, oldTime, newTime) -> {
            if (isColliding(square, smallCircle)) {
                isSquareTouched = true;
                square.setFill(Color.RED);
            } else {
                if (isSquareTouched) {
                    square.setFill(Color.BLACK);
                    isSquareTouched = false;
                }
            }
        });

        primaryStage.setScene(scene);
        primaryStage.show();
    }

    // Método para verificar la colisión entre dos objetos del tipo 'Shape' (reutilizable!!!)
    private boolean isColliding(Shape shape1, Shape shape2) {
        return Shape.intersect(shape1, shape2).getBoundsInLocal().getWidth() != -1;
    }
}
