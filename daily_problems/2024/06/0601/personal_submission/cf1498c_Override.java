
import java.io.*;
import java.lang.reflect.Array;
import java.util.Arrays;

public class c1498 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
    static int N = 1010,mod =1000000000+7;
    static int t,n,k;
    static long[][] dp = new long[N][N];
    public static void main(String[] args)throws Exception{
        t = nextInt();
        while (t-- >0){
            n = nextInt();
            k = nextInt();
//            Arrays.fill(dp,0L);  这里存疑
            for(int i=1;i<=k;i++) dp[i][0]=1;
            for(int i=1;i<=n;i++) dp[1][i]=1;
            for(int i=1;i<=k;i++){
                for(int j=1;j<=n;j++){
                    dp[i][j] = (dp[i][j-1]+dp[i-1][n-j])%mod;
                }
            }
            pw.println(dp[k][n]);
        }
        pw.flush();
    }
}
