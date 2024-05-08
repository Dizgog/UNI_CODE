/*
 * Main.java
 * @author R.Vaicekauskas
 * Pirmosios užduoties sprendimo java šablonas
 */

// Irašyti reikiamą paketo vardą
//package pirmoji;

/**
 * Dirbant NetBeans aplinkoje klasė "Main" sugeneruojama automatiškai
 */
public class Main {
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       System.out.println("Programa pradeda darba");
       TestThread.pradeti();       
       System.out.println("Programa baigia darba.");
    }
}

/*
   Naujai sukurta klase.
   Gijos klasė, turi būti išvesta iš Thread
*/
class TestThread extends Thread
{
   // Gijos objekto specifiniai duomenys
   BendroNaudojimoObjektas bendras;
   
   // Konstruktorius, skirtas perduoti duomenis gijos objektui
   public TestThread(BendroNaudojimoObjektas bendras) 
   {
      this.bendras = bendras;
   }

   // Metodas, vykdomas paleidus giją
   // Thread.run()
   public void run()
   {
      System.out.println("Gija " + this + " paleista");

      // Ciklas (didesnis iteracijų skaičius padidina duomenų skaitymo 
	  // atnaujinimo konflikto galimybę
      for (int i = 0; i < 100; i++)
      {
	     // Sinchronizuoto bloko pradžia
		 // Bloko viduje galima saugiai skaityti/modifikuoti 
		 // Objekto bendras laukus
		 // *** Užkomentavus turėtų atsirasti duomenų atnaujinimo konfliktai ***
         synchronized(bendras) 
         {
	 	     // Kontrolinis spausdinimas, kad įsitikinti vienalaikiu gijų veikimu 
		     System.out.println("Gija " + this + " pries atnaujinant bendra kintamaji");
			 
			 // Kviečiame metodą, kuris modifikuoja objekto lauko reikšmę
			 // *** Konkrečiam taikymui metodo kvietinys/iai turi būti pakeistas/i***
             bendras.padidinti(); 

	 	     // Kontrolinis spausdinimas, kad įsitikinti vienalaikiu gijų veikimu 
		     System.out.println("Gija " + this + " atnaujino bendra kintamaji");
         }
      }
      System.out.println("Gija " + this + " baigia darbą");
   }
   
   // Metodas paleidžiantis gijas darbui ir išvedantis rezultatą
   public static void pradeti()
   {
         // Sukuriame objektą, kurį bendrai naudos kelios gijos 	
         BendroNaudojimoObjektas bendras = new BendroNaudojimoObjektas();
         bendras.n = 0; // Pradinė reikšmė
		 
         try
         { 
		       // Sukuriame ir startuojame pirmąją giją
			   // perduodami kaip parametrą objektą "bendras"
               Thread t1 = new TestThread(bendras); 
               t1.start();
			   
		       // Sukuriame ir startuojame pirmąją giją
               Thread t2 = new TestThread(bendras);
               t2.start();

			   // Laukiame, kol abi gijos baigs darbą 
               t1.join();  t2.join();
			   
			   // Išvedame galutinį rezultatą
               System.out.println("Rezultatas n = " + bendras.n + ". Turi buti 10");
         } 
         catch (InterruptedException exc)
         {
            System.out.println("Ivyko klaida "+exc);
         }
   }
}

/*
Klasė, aprašanti bendrai gijų naudojamą objektą
*** Konkrečiam taikymui turi būti pakeistas***
*/
class BendroNaudojimoObjektas
{
    // Laukas, kurį skaitys modifikuos kelios gijos
    int n;
	
	// Metodas modifikuojantis objekto turinį
	public void padidinti() 
        {
           int nn = n; // Nuskaityti
           nn++;       // Apskaiciuoti
           n = nn;     // Isiminti objekto lauke
           System.out.println(n);
        }
}