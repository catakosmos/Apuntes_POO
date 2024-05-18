public class AirConditioner extends DomoticDevice { 
 public AirConditioner (int channel){
 super(nextId++, channel);
 temp = 20;
 state = PowerState.OFF;
 }
 public void changePowerState(){
 state = state==PowerState.ON ? PowerState.OFF : PowerState.ON;
 }
 public void setTemp(int t){
 if (state==PowerState.ON)
 temp = t;
 }
 public String getHeader(){
 String s = "State\t" + "AC" + getId() + "T";
 return s;
 }
 public String toString(){
 return state.toString() + "\t" + temp;
 }
 private int temp;
 private PowerState state;
 private static int nextId=0;
}
public class AC_Control extends DomoticDeviceControl{. // 8 pts.
 public AC_Control(int channel, Cloud c){
 super(channel,c);
 }
 public void setT(int temp){
 cloud.setACtemp(channel, temp);
 }
 public void pressPower(){
 cloud.changeACpowerState(channel);
