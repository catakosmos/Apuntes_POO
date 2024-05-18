public class MainFX extends Application {
 public void start(Stage primaryStage) {
 Cloud cloud = new Cloud();
 Lamp lamp = new Lamp(1);
 cloud.addLamp(lamp);
 LampControl lampControl = new LampControl(1, cloud);
 StackPane pane = new StackPane();
 Button lampB = new Button("Power");
 pane.getChildren().add(lampB);
 lampB.setOnAction(e->{lampControl.pressPower();System.out.println(cloud.getState());});
 Scene scene = new Scene(pane, 200, 50);
 primaryStage.setScene(scene);
 primaryStage.show();
