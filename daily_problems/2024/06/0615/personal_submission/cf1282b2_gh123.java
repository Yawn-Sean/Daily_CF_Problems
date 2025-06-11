//https://codeforces.com/problemset/submission/1282/265830211
import java.util.Arrays;
import java.util.Scanner;

public class B1282 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            int p=sc.nextInt();
            int k=sc.nextInt();
            int[]a=new int[n+1];
            int[]dp=new int[200001];
            for (int i = 1; i <=n; i++) {
                a[i]=sc.nextInt();
                dp[i]=0;
            }
            Arrays.sort(a);
            for (int i = 1; i <=n; i++) {
                if(i<k) dp[i]=dp[i-1]+a[i];
                else{
                    dp[i]=Math.min(dp[i-k]+a[i], dp[i-1]+a[i]);
                }
            }
            int ans=0;
            for (int i = n; i >=1; i--) {
                if(dp[i]<=p){
                    ans=i;
                    break;
                }
            }
            System.out.println(ans);
        }
        sc.close();
    }
}
