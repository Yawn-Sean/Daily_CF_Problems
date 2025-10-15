//https://codeforces.com/problemset/submission/269/317796759
import java.util.Arrays;
import java.util.Scanner;

public class B269 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[]a=new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i]=sc.nextInt();
            String tem=sc.next();
        }   
        sc.close();
        int[]dp=new int[n];
        Arrays.fill(dp, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if(a[j]<=a[i]){
                    dp[i]=Math.max(dp[i], dp[j]+1);
                }
            }
        }
        int max=0;
        for (int i = 0; i < dp.length; i++) {
            max=Math.max(max, dp[i]);
        }
        System.out.println(n-max);
    }
}
