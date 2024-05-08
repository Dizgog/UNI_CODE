import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

public class Main {

	public static void main(String[] args) {
		int n = Integer.parseInt(args[0]);
		ThreadPoolExecutor executor = 
				new ThreadPoolExecutor(
						Integer.parseInt(args[1]),
						n,
						100,
						TimeUnit.MILLISECONDS, 
						new ArrayBlockingQueue<Runnable>(
	            n));
		
		long startedTime = System.currentTimeMillis();
		
		for(int i=1; i<=n; i++) {
			int[] vietos = new int[n+1];
			vietos[1] = i;
			executor.execute(new Karalienes(n, 2, vietos));
		}
		
		executor.shutdown();
		try {
			executor.awaitTermination(60, TimeUnit.MINUTES);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println("Darbo laikas: "+(float)(System.currentTimeMillis()-startedTime)/1000+" s.");
		System.out.println("Rasta rezultatu: "+Karalienes.getVariantuSkaiciu());
	}

}
