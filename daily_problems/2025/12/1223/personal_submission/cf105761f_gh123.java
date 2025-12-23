import java.util.Scanner;

public class F105761 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int p=sc.nextInt();
        p=Math.min(p, 20);
        int inf=(int)1e9;
        long[][]dp=new long[p+1][n+1];
        for (int i = 0; i <=n; i++) {
            dp[0][i]=1;
        }   
        sc.close();
        for (int i = 1; i <=p; i++) {
            dp[i][0]=1;
            for (int j = 1; j <=n; j++) {
                dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                if(dp[i][j]==inf){
                    dp[i][j]=inf;
                }
            }
        }
        for (int i = 0; i <=n; i++) {
            if(dp[p][i]>=n){
                System.out.println(i);
                break;
            }
        }
    }
}
