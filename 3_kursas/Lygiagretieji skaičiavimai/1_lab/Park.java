class ParkingLotThread extends Thread {
    private park parkingLot;

    public ParkingLotThread(park parkingLot) {
        this.parkingLot = parkingLot;
    }

    // Method to simulate a vehicle entering the parking lot
    public void enter() {
        if (parkingLot.getAvailableSpaces() > 0) {
            // Simulate delay to magnify the race condition
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            parkingLot.decrementAvailableSpaces();
            System.out.println(Thread.currentThread().getName() + " entered the parking lot. Available spaces: " + parkingLot.getAvailableSpaces());
        } else {
            System.out.println(Thread.currentThread().getName() + " - Parking lot is full. Unable to enter.");
        }
    }

    @Override
    public void run() {
        for (int i = 0; i < 12; i++) { // Simulate vehicle operations
            enter(); // Simulate vehicle entering
        }
    }
}

public class Park {
    private int availableSpaces;

    public Park(int totalSpaces) {
        this.availableSpaces = totalSpaces;
    }

    public int getAvailableSpaces() {
        return availableSpaces;
    }

    public void decrementAvailableSpaces() {
        availableSpaces--;
    }

    public static void main(String[] args) {
        Park parkingLot = new Park(10); // Total parking spaces = 10

        // Creating and starting two threads to simulate vehicles entering the parking lot
        ParkingLotThread FirstThread = new ParkingLotThread(parkingLot);
        ParkingLotThread SecondThread = new ParkingLotThread(parkingLot);

        FirstThread.setName("First Thread");
        SecondThread.setName("Second Thread");

        FirstThread.start();
        SecondThread.start();

        // Waiting for both threads to finish
        try {
            FirstThread.join();
            SecondThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Calculate the difference between the initial and final number of available spaces
        int difference = 10 - parkingLot.getAvailableSpaces();
        System.out.println("Difference in available spaces: " + difference);
    }
}
