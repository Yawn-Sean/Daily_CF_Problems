//https://codeforces.com/problemset/submission/429/283324401
import java.util.Scanner;

public class B429 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int k=1005;
        int[][]dp1=new int[k][k];
        int[][]dp2=new int[k][k];
        int[][]dp3=new int[k][k];
        int[][]dp4=new int[k][k];
        int[][]a=new int[k][k];
        for (int i = 1; i <=n; i++) {
            for (int j = 1; j <=m; j++) {
                a[i][j]=sc.nextInt();
            }
        }
        for (int i = 1; i <=n; i++) {
            for (int j = 1; j <m; j++) {
                dp1[i][j]=Math.max(dp1[i-1][j],dp1[i][j-1])+a[i][j];
            }
        }
        for (int i = n; i >=1; i--) {
            for (int j = m; j >0; j--) {
                dp2[i][j]=Math.max(dp2[i+1][j], dp2[i][j+1])+a[i][j];
            }
        }
        for (int i = 1; i <=n; i++) {
            for (int j = m; j >=1; j--) {
                dp3[i][j]=Math.max(dp3[i-1][j], dp3[i][j+1])+a[i][j];
            }
        }
        for (int i = n; i >0; i--) {
            for (int j = 1; j <=m; j++) {
                dp4[i][j]=Math.max(dp4[i+1][j],dp4[i][j-1])+a[i][j];
            }
        }
        int ans=0;
        for (int i = 2; i < n; i++) {
            for (int j = 2; j < m; j++) {
                ans=Math.max(ans, dp1[i-1][j]+dp2[i+1][j]+dp3[i][j+1]+dp4[i][j-1]);
                ans=Math.max(ans, dp1[i][j-1]+dp2[i][j+1]+dp3[i-1][j]+dp4[i+1][j]);
            }
        }
        System.out.println(ans);
//这道dp挺难的。。。我不会
        sc.close();
    }
}
