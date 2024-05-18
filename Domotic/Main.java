import java.io.PrintStream;

public class Main {
    public static void main(String [] args) {
        double time=0;
        PrintStream out = System.out;
        Cloud cloud = new Cloud();
        Lamp lamp = new Lamp(1);
        cloud.addLamp(lamp);
        LampControl lampControl = new LampControl(1, cloud);

        out.println("Time\t" + cloud.getHeaders());
        out.println(time+"\t"+cloud.getState());
        time = 2;
        lampControl.pressPower();
        out.println(time+"\t"+cloud.getState());
        time = 5;
        lampControl.pressPower();
        out.println(time+"\t"+cloud.getState());
    }
}
