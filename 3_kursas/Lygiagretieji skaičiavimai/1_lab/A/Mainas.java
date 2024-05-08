class ParkingLotThread extends Thread {
    private Mainas parkingLot;

    public ParkingLotThread(Mainas parkingLot) {
        this.parkingLot = parkingLot;
    }

    // Method to simulate a vehicle entering the parking lot
    public void enter() {
      // synchronized (parkingLot) {
        if (parkingLot.getAvailableSpaces() > 0) {
            parkingLot.decrementAvailableSpaces();
        } 
        //}
    }

    @Override
    public void run() {
        boolean flag = GlobalVariables.globalBoolean;
        System.out.println(flag);
        if (flag=true) {
        for (int i = 0; i < 120000; i++) { // Simulate vehicle operations
            enter(); // Simulate vehicle entering
        }
    }
}
}

public class GlobalVariables {
    public static volatile boolean globalBoolean = false;
}



public class Mainas {
    private int availableSpaces;

    public Mainas(int totalSpaces) {
        this.availableSpaces = totalSpaces;
    }

    public int getAvailableSpaces() {
        return availableSpaces;
    }

    public void decrementAvailableSpaces() {
        availableSpaces--;
    }

    public static void main(String[] args) {
        Mainas parkingLot = new Mainas(100000); // Total parking spaces = 10

        // Creating and starting two threads to simulate vehicles entering the parking lot
        ParkingLotThread FirstThread = new ParkingLotThread(parkingLot);
        ParkingLotThread SecondThread = new ParkingLotThread(parkingLot);

        FirstThread.setName("First Thread");
        SecondThread.setName("Second Thread");

        FirstThread.start();
        SecondThread.start();
        GlobalVariables.globalBoolean = true;
        // Waiting for both threads to finish
        try {
            FirstThread.join();
            SecondThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Calculate the difference between the initial and final number of available spaces
        int difference = parkingLot.getAvailableSpaces();
        System.out.println("Difference in available spaces: " + difference + " should be 0");
    }
}
