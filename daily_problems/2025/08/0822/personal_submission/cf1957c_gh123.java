//https://codeforces.com/problemset/submission/1957/334971427
import java.util.Scanner;
//dp总是想不到状态转移方程.
public class C1957 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int mod=(int)1e9+7,m=(int)3e5;
        int[]dp=new int[m+1];
        dp[0]=1;dp[1]=1;
        for (int i = 2; i <=m; i++) {
            dp[i]=(int)((2l*(i-1)*dp[i-2]+dp[i-1])%mod);
        }
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            int k=sc.nextInt();
            while (k-->0) {
                int x=sc.nextInt(),y=sc.nextInt();
                if(x==y){
                    n--;
                }else{
                    n-=2;
                }
            }
            System.out.println(dp[n]);
        }
        sc.close();
    }
}
