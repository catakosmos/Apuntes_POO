import javafx.application.Application;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Circle;
import javafx.scene.paint.Color; // los import no otorgan puntaje (lo hace el IDE)

public class JavaFxDetector extends Application {
 public void start(Stage primaryStage) {
 Pane pane = new StackPane();
 Circle circle = new Circle();
 circle.setRadius(30);          // el detector es un círculo de radio 30 pixeles ubicado en el centro de la ventana
 circle.setStroke(Color.BLACK);
 circle.setFill(Color.WHITE);
 circle.setOnMouseEntered(e->System.out.println("Detectado")); // la mosca se representa con el mouse
 pane.getChildren().add(circle);
 Scene scene = new Scene(pane, 200, 200);
 primaryStage.setTitle("P2b");
 primaryStage.setScene(scene);
 primaryStage.show();
 }
}
