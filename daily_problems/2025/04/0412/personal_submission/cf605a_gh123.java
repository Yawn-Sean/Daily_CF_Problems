//https://codeforces.com/problemset/submission/605/315074806
import java.util.Scanner;

public class A605 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]dp=new int[n+1];
        for (int i = 0; i < n; i++) {
            int x=sc.nextInt();
            dp[x]=dp[x-1]+1;
        }   
        sc.close();
        int max=0;
        for (int i = 0; i <=n; i++) {
            max=Math.max(max, dp[i]);
        }
        System.out.println(n-max);
    }
}
