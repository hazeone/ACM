
public class tmp implements Runnable{
     public void run(){
         System.out.println("hhh");
     }
     public static void main(String[] args) {
         Float a=1.0;
         tmp rt = new tmp();
         Thread t = new Thread(rt);
         t.start();
     }
 }
