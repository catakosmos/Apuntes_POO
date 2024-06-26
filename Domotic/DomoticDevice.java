public abstract class DomoticDevice {
    public DomoticDevice(int id, int ch){
        this.id= id;
        channel = ch;
    }
    public int getChannel() {
        return channel;
    }
    public int getId() {
        return id;
    }
    public abstract String getHeader();
    private final int id;
    private int channel;
}
