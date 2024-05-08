class ParkingLotThread extends Thread {
    private Mainas parkingLot;

    public ParkingLotThread(Mainas parkingLot) {
        this.parkingLot = parkingLot;
    }

    // Metodas, simuliuojantis automobilio įvažiavimą į automobilių stovėjimo aikštelę
    public void enter() {
      //  synchronized (parkingLot) {
            if (parkingLot.getAvailableSpaces() > 0) {
                parkingLot.decrementAvailableSpaces();
                //System.out.println(Thread.currentThread().getName() + " įvažiavo į automobilių stovėjimo aikštelę. Laisvos vietos: " + parkingLot.getAvailableSpaces());
            } else {
                //System.out.println(Thread.currentThread().getName() + " - Automobilių stovėjimo aikštelė pilna. Negalima įvažiuoti.");
            }
        //}
    }

    // Metodas, simuliuojantis automobilio išvažiavimą iš automobilių stovėjimo aikštelės
    //Kritine sekcija
    public void exit() {
     //  synchronized (parkingLot) {
            if (parkingLot.getAvailableSpaces() < 20000) { // Tariame, kad aikštelės maksimalus talpumas - 10 vietų
                parkingLot.incrementAvailableSpaces();
              //  System.out.println(Thread.currentThread().getName() + " isvaziavo is automobiliu stovejimo aiksteles. Laisvos vietos: " + parkingLot.getAvailableSpaces());
            } else {
                //System.out.println(Thread.currentThread().getName() + " - Automobiliu stovejimo aikstele jau tuscia. Negalima isvaziuoti.");
            }
       // }
    }

    @Override
    public void run() {
        for (int i = 0; i < 12; i++) { // Simuliuoti automobilių veiksmus
            if (i % 2 == 0) {
                enter(); // Kiekvieno lyginio pasikartojimo metu simuliuoti automobilio įvažiavimą
            } else {
                exit(); // Kiekvieno nelyginio pasikartojimo metu simuliuoti automobilio išvažiavimą
            }
            /*try {
                Thread.sleep(100); // Simuliuoti šiek tiek vėlavimo tarp automobilių veiksmų
            } catch (InterruptedException e) {
                e.printStackTrace();
            }*/
            
        }
    }
}

public class Mainas {
    private int availableSpaces;

    public Mainas(int totalSpaces) {
        this.availableSpaces = totalSpaces;
    }

    public synchronized int getAvailableSpaces() {
        return availableSpaces;
    }

    public synchronized void decrementAvailableSpaces() {
        availableSpaces--;
    }

    public synchronized void incrementAvailableSpaces() {
        availableSpaces++;
    }

    public static void main(String[] args) {
        Mainas parkingLot = new Mainas(10); // Iš viso automobilių stovėjimo aikštelėje vietų - 10

        // Sukuriame ir paleidžiame dvi gijas, simuliuojančias automobilių įvažiavimą ir išvažiavimą iš automobilių stovėjimo aikštelės
        ParkingLotThread PirmojiGija = new ParkingLotThread(parkingLot);
        ParkingLotThread AntrojiGija = new ParkingLotThread(parkingLot);

        PirmojiGija.setName("Pirmoji Gija");
        AntrojiGija.setName("Antroji Gija");

        PirmojiGija.start();
        AntrojiGija.start();

        try {
            PirmojiGija.join();
            AntrojiGija.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
       // System.out.println("Gija " + PirmojiGija + " baigia darba");
       // System.out.println("Gija " + AntrojiGija + " baigia darba");
       //System.out.println("Rezultatas n = " + parkingLot.getAvailableSpaces() + ". Turi buti 10");
       int difference = 10 - parkingLot.getAvailableSpaces();
        System.out.println("Difference in available spaces: " + difference);

    }
}
