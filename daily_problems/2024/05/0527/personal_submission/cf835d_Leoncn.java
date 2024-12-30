import java.io.PrintWriter;

public class cf835d_Leoncn {
        static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    public static void solve() {
        char[] cs = sc.ns().toCharArray();
        int n = cs.length;
        int[] ans = new int[n];
        int[][] dp = new int[n][n];
        for (int k = 1; k <= n; k++) {
            for (int i = 0; i <n-k+1 ; i++) {
                if(k == 1){
                    dp[i][i] = 1;
                    ans[0] ++;
                }else if(k == 2){
                    if(cs[i] == cs[i+1]){
                        dp[i][i+1] = 2;
                        ans[1]++;
                    }
                }else{
                    if(dp[i+1][i+k-2]>0 && cs[i] == cs[i+k-1]){
                        int res = dp[i][i+k/2-1] + 1;
                        dp[i][i+k-1] = res;
                        ans[res-1] ++;
                    }

                }

            }
        }
        for (int i = n-2; i >=0 ; i--) {
            ans[i] += ans[i+1];
        }
        for (int i = 0; i < n; i++) {
            out.print(ans[i] + " ");
        }
    }
}
