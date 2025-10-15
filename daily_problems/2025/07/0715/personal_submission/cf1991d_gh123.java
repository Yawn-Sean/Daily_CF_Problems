//https://codeforces.com/problemset/submission/1991/328975985
import java.util.Scanner;

public class D1991 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            if(n<6){
                System.out.println(n/2+1);
                for (int i = 1; i <=n; i++) {
                    System.out.print((i/2+1)+" ");
                }
            }else{
                System.out.println(4);
                for (int i = 1; i <=n; i++) {
                    System.out.print((i%4+1)+" ");
                }
                System.out.println();
            }
        }
        sc.close();
    }
}
