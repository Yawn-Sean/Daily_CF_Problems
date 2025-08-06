//https://codeforces.com/problemset/submission/269/332588371
import java.util.Scanner;

public class A269 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int ans=0;
        while (n-->0) {
            int k=sc.nextInt();
            int x=sc.nextInt();
            ans=Math.max(ans, k+1);
            while (x>1) {
                x=(x+3)/4;
                k++;
            }
            ans=Math.max(ans, k);
        }   
        System.out.println(ans);
        sc.close();
    }
}
