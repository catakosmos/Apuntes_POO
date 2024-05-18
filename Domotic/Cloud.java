import java.util.ArrayList;

public class Cloud {
    public Cloud() {
        lamps = new ArrayList<DomoticDevice>();
    }
    public void addLamp(Lamp l){
        lamps.add(l);
    }
    private DomoticDevice getDomoticDeviceAtChannel( ArrayList<DomoticDevice> devices, int channel){
        for (DomoticDevice device: devices)
            if (device.getChannel() ==channel)
                return device;
        return null;
    }
    public void changeLampPowerState(int channel){
        Lamp l=(Lamp) getDomoticDeviceAtChannel(lamps, channel);
        if (l != null) l.changePowerState();
    }
    public String getHeaders(){
        String header = "";
        for (DomoticDevice l: lamps)
            header += l.getHeader()+"\t";
        return header;
    }
    public String getState(){
        String state="";
        for (DomoticDevice l: lamps) {
            state += l+ "\t";
        }
        return state;
    }
    private ArrayList<DomoticDevice> lamps;
}
