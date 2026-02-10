import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class cf102946d {
    private static final Scanner sc=new Scanner(System.in);
    private static final PrintWriter out=new PrintWriter(new OutputStreamWriter(System.out), true);
      public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int idx=-1;
        boolean flag=false;
        for (int i = 0; i < n; i++) {
            if(query(0,i)==n){
                if(idx!=-1){
                    flag=true;
                }
                idx=i;
            }
        }
        if(!flag){
            int toq=(idx!=0)?idx-1:1;
            for (int i = 0; i < n; i++) {
                if(query(i,toq)==n){
                    out.println("! "+(idx-i+n)%n);
                    break;
                }
            }
        }else{
            for (int i = 0; i < n; i++) {
                if(query(1,i)==n){
                    out.println("! "+i);
                    break;
                }
            }
        }
        sc.close();
      }  
      private static int query(int i,int j){
        out.println("? "+i+" "+j);
        int res=sc.nextInt();
        return res;
      }
}
