import java.io.PrintStream;

public class MainAC {
    public static void main(String [] args) {
        double time=0;
        PrintStream out = System.out;
        Cloud cloud = new Cloud();
        Lamp lamp = new Lamp(1);
        cloud.addLamp(lamp);
        AirConditioner ac = new AirConditioner(2);
        cloud.addAirConditioner(ac);
        LampControl lampControl = new LampControl(1, cloud);
        AC_Control acControl = new AC_Control(2, cloud);

        out.println("Time\t" + cloud.getHeaders());
        out.println(time+"\t"+cloud.getState());
        time = 2;
        lampControl.pressPower();
        out.println(time+"\t"+cloud.getState());
        time = 5;
        lampControl.pressPower();
        out.println(time+"\t"+cloud.getState());
        time =6;
        acControl.setT(23);
        out.println(time+"\t"+cloud.getState());
        acControl.pressPower();
        out.println(time+"\t"+cloud.getState());
        acControl.setT(21);
        out.println(time+"\t"+cloud.getState());
    }
}
