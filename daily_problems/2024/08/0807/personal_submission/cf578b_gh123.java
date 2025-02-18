//https://codeforces.com/problemset/submission/578/275010225
//一遇到位运算，就晕了。。。
import java.util.Scanner;

public class B578 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        int x=sc.nextInt();
        int[]a=new int[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
        }
        sc.close();
        int[]pre=new int[n];
        int tem=0;
        for (int i = 0; i < n; i++) {
            pre[i]=tem;
            tem|=a[i];
        }
        int[]suf=new int[n];
        tem=0;
        for (int i = n-1; i >=0; i--) {
            suf[i]=tem;
            tem|=a[i];
        }
        long pow=1;
        while (k-->0) {
            pow*=x;
        }
        long ans=0;
        for (int i = 0; i < n; i++) {
            ans=Math.max(ans, a[i]*pow|pre[i]|suf[i]);
        }
        System.out.println(ans);

    }
}
