class EventCounter {
    private int count;
    private boolean state;
    //int[] array = new int[10000];

    public EventCounter() {
        this.count = 0;
        this.state = true;
    }

    public synchronized void advance() {
      //  array[count] = count + 1;
        count++;
        notifyAll();
    }

    public synchronized int read() {
        //return array.length;
        return count;
    }

    public synchronized void await(int value) throws InterruptedException {
        while (count < value) {
            wait();
        }
    }
    public synchronized boolean isFull() {
        return state;
    }
    public synchronized void setFull(boolean state) {
        this.state = state;
    }
}

public class Main {
    public static void main(String[] args) {
        EventCounter eventCounter = new EventCounter();
        int N = 1000;
       int[] array = new int[N];

       new Thread(() -> {
        
        for (int i = 0; i < N; i++) { 
            try {
                eventCounter.await(i + 1);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            if ((array[i]) != i + 1){
                System.out.println("Blogai" + i + " " + array[i] + " " + (i + 1));
            }
            //eventCounter.advance();
        }
}).start();

        new Thread(() -> {
                for (int i = 0; i < N; i++) { 
                    array[i] = i + 1;
                eventCounter.advance();
                }
        }).start();
    }
}
