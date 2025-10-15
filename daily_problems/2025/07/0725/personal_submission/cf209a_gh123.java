//https://codeforces.com/problemset/submission/209/330746460
import java.util.Scanner;

public class A209 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int mod=(int)1e9+7;
        int dp0=0,dp1=0;
        for (int i = 0; i < n; i++) {
            if(i%2==0){
                dp0=(dp0+dp1+1)%mod;
            }else{
                dp1=(dp0+dp1+1)%mod;
            }
        }
        System.out.println((dp0+dp1)%mod);
        sc.close();
    }
}
