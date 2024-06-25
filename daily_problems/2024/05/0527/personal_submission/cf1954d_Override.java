import java.io.*;
import java.util.Arrays;

public class d1954 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }

    static int N = 5005;
    static int mod = 998244353;
    static int n;
    static int[] a = new int[N];
    static long[] dp = new long[N];
    static long res;

    public static void main(String[] args)throws Exception{
        n = nextInt();
        for(int i=1;i<=n;i++){
            a[i]=nextInt();
        }
        Arrays.sort(a,1,n+1);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=5000;j>=a[i]+1;j--){
                res = (res + (j+a[i]+1)/2*dp[j]%mod)%mod;
                if(j+a[i]<=5000) dp[j+a[i]]=(dp[j+a[i]]+dp[j])%mod;
            }
            for(int j=a[i];j>=0;j--){
                res = (res+dp[j]*a[i]%mod)%mod;
                if(j+a[i]<=5000) dp[j+a[i]]=(dp[j+a[i]]+dp[j])%mod;
            }
        }
        pw.println(res);
        pw.flush();
    }
}
