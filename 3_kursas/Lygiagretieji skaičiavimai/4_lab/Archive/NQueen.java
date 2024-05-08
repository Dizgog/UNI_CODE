import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;

public class NQueen implements Runnable {
    private int boardSize;
    private int column;
    private int[] positions;
    private static AtomicInteger solutionCount = new AtomicInteger(0);

    public NQueen(int boardSize, int column, int[] positions) {
        this.boardSize = boardSize;
        this.column = column;
        this.positions = positions.clone(); // Clone the array to prevent shared mutable state among threads
    }

    private boolean isSafe(int row, int column) {
        for (int prevColumn = column - 1; prevColumn >= 1; prevColumn--) {
            if (positions[prevColumn] == row || Math.abs(positions[prevColumn] - row) == Math.abs(column - prevColumn)) {
                return false;
            }
        }
        return true;
    }

    public void placeQueens() {
        for (int row = 1; row <= boardSize; row++) {
            positions[column] = row;
            if (isSafe(row, column)) {
                if (column < boardSize) {
                    column++;
                    placeQueens();
                    column--;
                } else if (column == boardSize) {
                    solutionCount.incrementAndGet();
                }
            }
        }
    }

    @Override
    public void run() {
        placeQueens();
    }

    public static int getSolutionCount() {
        return solutionCount.get();
    }

    public static void main(String[] args) {
        int[] boardSizes = {2, 4, 8, 16, 32};
        int maxCore = 32;

        for (int boardSize : boardSizes) {
            for (int core = 8; core <= maxCore; core++) {
                ThreadPoolExecutor executor =
                        new ThreadPoolExecutor(
                                core,
                                core,
                                100,
                                TimeUnit.MILLISECONDS,
                                new ArrayBlockingQueue<>(core * (boardSize + 1))); // Increase the capacity of the task queue

                long startTime = System.currentTimeMillis();

                for (int i = 1; i <= boardSize; i++) {
                    int[] positions = new int[boardSize + 1];
                    positions[1] = i;
                    executor.execute(new NQueen(boardSize, 2, positions));
                }

                executor.shutdown();
                try {
                    executor.awaitTermination(60, TimeUnit.MINUTES);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

                // Ensure all tasks are completed before counting solutions
                while (!executor.isTerminated()) {
                    // Wait for all tasks to complete
                }
                    System.out.println("Board Size: " + boardSize + ", Cores: " + core + ", Found Solutions: " + NQueen.getSolutionCount() + ", Execution Time: " + (float) (System.currentTimeMillis() - startTime) / 1000 + " s.");
                // Reset solution count for next iteration
                solutionCount.set(0);
            }
        }
    }
}
