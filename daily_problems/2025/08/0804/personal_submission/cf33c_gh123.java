//https://codeforces.com/problemset/submission/33/332299116
import java.util.Scanner;
//不会 dp...
public class C33 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]a=new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i]=sc.nextInt();
        }   
        sc.close();
        int[]suf=new int[n+1];
        int[]sufmin=new int[n+1];
        for (int i = n-1; i >=0; i--) {
            suf[i]=suf[i+1]+a[i];
        }
        sufmin[n]=0;
        for (int i = n-1; i >=0; i--) {
            sufmin[i]=Math.min(sufmin[i+1], suf[i]);
        }
        long ans=Math.max(suf[0], -suf[0]);
        long pre=0;
        for (int i = 0; i < n; i++) {
            ans=Math.max(ans, suf[0]-2*(pre+sufmin[i]));
            pre+=a[i];
        }
        System.out.println(ans);
    }
}
