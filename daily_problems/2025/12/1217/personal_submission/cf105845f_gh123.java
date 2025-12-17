import java.util.Scanner;

public class F105845 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int mod=(int)1e9+7;
        int[]dp=new int[n+1];   
        sc.close();
        dp[0]=1;
        int ans=0;
        for (int i = 1; i <=n; i++) {
            int[]ndp=new int[n+1];
            int[]save=new int[i];
            int cur=0;
            for (int j = 0; j <=n; j++) {
                cur=(cur+j)%i;
                ndp[j]=save[cur];
                save[cur]=(save[cur]+dp[j])%mod;
            }
            dp=ndp;
            ans=(ans+dp[n])%mod;
        }
        System.out.println(ans);
    }
}
