import java.io.*;
import java.util.Arrays;

public class b21282 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
    public static void main(String[] args)throws Exception{
        int t;
        t = nextInt();
        while (t-->0){
            int n,p,k;
            n = nextInt();
            p = nextInt();
            k = nextInt();
            int[] dp = new int[n+1];   //n n+1
            for(int i=1;i<=n;i++){
                dp[i] = nextInt();
            }
            Arrays.sort(dp);
            for(int i=1;i<k;i++){
                dp[i] += dp[i-1];
            }
            for(int i=k;i<=n;i++){
                dp[i] += dp[i-k];
            }

            int  ans = 0;
            for(int i=n;i>=0;i--){
                if(dp[i] <= p){
                    ans = i;
                    break;
                }
            }

            pw.println(ans);
            pw.flush();

        }
    }
}
