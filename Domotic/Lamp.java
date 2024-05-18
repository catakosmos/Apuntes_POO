public class Lamp extends DomoticDevice {
    public Lamp (int channel){
        super(nextId++, channel);
        r=g=b= 255;
        state = PowerState.OFF;
    }
    public void changePowerState(){
        state = state==PowerState.ON ? PowerState.ON.OFF : PowerState.ON.ON;
    }
    public String getHeader(){
        String s = "State\t" + "L" + getId() + "R\t" + "L" + getId() + "G\t" + "L" + getId() + "B";
        return s;
    }
    public String toString(){
        return state.toString() + "\t"+r+"\t"+g+"\t"+b;
    }
    private short r,g,b;
    private PowerState state;
    private static int nextId=0;
}
