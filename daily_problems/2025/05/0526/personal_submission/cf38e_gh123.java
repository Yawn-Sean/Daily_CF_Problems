//https://codeforces.com/problemset/submission/38/321321716
import java.util.Arrays;
import java.util.Scanner;

public class E38 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long[][]arr=new long[n][2];
        for (int i = 0; i < n; i++) {
            arr[i][0]=sc.nextLong();
            arr[i][1]=sc.nextLong();
        }   
        sc.close();
        Arrays.sort(arr,(a,b)->Long.compare(a[0], b[0]));
        long[][]dp=new long[n][2];
        dp[0][1]=arr[0][1];
        dp[0][0]=Long.MAX_VALUE;
        for (int i = 1; i < n; i++) {
            dp[i][1]=Math.min(dp[i-1][0],dp[i-1][1])+arr[i][1];
            long tem=0;
            dp[i][0]=Long.MAX_VALUE;
            for (int j = i-1; j >=0; j--) {
                tem+=(arr[j+1][0]-arr[j][0])*(i-j);
                dp[i][0]=Math.min(dp[i][0], dp[j][1]+tem);
            }
        }
        System.out.println(Math.min(dp[n-1][0], dp[n-1][1]));
    }
}
