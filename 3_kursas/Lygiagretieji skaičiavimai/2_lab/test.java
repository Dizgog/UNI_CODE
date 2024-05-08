class ArrayLock {
    private boolean[] lockedElements;

    public ArrayLock(int size) {
        lockedElements = new boolean[size];
    }

    public synchronized void lock(int indexFrom, int indexTo) throws InterruptedException {
        for (int i = indexFrom; i <= indexTo; i++) {
            while (lockedElements[i]) {
                wait(); // Laukiama, kol elementas bus atlaisvintas kitos gijos
            }
            lockedElements[i] = true;
        }
    }

    public synchronized void unlock(int indexFrom, int indexTo) {
        for (int i = indexFrom; i <= indexTo; i++) {
            lockedElements[i] = false;
        }
        notifyAll(); // Pranešama visoms laukiančioms gijoms, kad elementai atlaisvinti
    }
}

class SortingThread extends Thread {
    private int[] array;
    private ArrayLock arrayLock;
    private int indexFrom;
    private int indexTo;

    public SortingThread(int[] array, ArrayLock arrayLock, int indexFrom, int indexTo) {
        this.array = array;
        this.arrayLock = arrayLock;
        this.indexFrom = indexFrom;
        this.indexTo = indexTo;
    }

    @Override
    public void run() {
        try {
            arrayLock.lock(indexFrom, indexTo);
            // Toliau vykdomas rušiavimas
            for (int i = 0; i <= array.length; i++) {
                for (int j = 0; j <= array.length - i - 2; j++) {
                    if (array[j] > array[j + 1]) {
                        int temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            arrayLock.unlock(indexFrom, indexTo);
        }
    }
}

public class test {
    public static void main(String[] args) {
        int[] array = {5, 3, 7, 1, 9, 2, 6, 4, 8, 0};
        ArrayLock arrayLock = new ArrayLock(array.length);
        int threads = 3; // Gijų skaičius

        // Sukuriamos ir paleidžiamos rušiavimo gijos
        SortingThread[] sortingThreads = new SortingThread[threads];
        for (int i = 0; i < threads; i++) {
            int startIndex = i * (array.length / threads);
            int endIndex = (i + 1) * (array.length / threads) - 1;
            sortingThreads[i] = new SortingThread(array, arrayLock, startIndex, endIndex);
            sortingThreads[i].start();
        }

        // Laukiama, kol visas rušiavimas baigsis
        for (SortingThread thread : sortingThreads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        // Spausdinamas surūšiuotas masyvas
        System.out.println("Surūšiuotas masyvas:");
        for (int num : array) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
