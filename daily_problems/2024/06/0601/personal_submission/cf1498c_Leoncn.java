public class cf1498c_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = sc.ni();
        while (t-- > 0) {
            solve();
        }

        out.close();
    }

    public static void solve() {
        int n = sc.ni();
        int k = sc.ni();
        int mod = (int) 1e9+7;
        if(k == 1){
            out.println(1);
            return;
        }
        long[][][] cnt = new long[k+1][n+3][2];
        cnt[k][1][0] = 1;
        for (int i = k; i >1 ; i--) {
            for (int j = 1; j <= n; j++) {
                cnt[i-1][j][1] = (cnt[i][j][0] + cnt[i-1][j-1][1])%mod;
                cnt[i][n+1][0] = (cnt[i][n+1][0] + cnt[i][j][0])%mod;
            }


            for (int j = n+1; j >1 ; j--) {
                cnt[i-1][j][0] = (cnt[i][j][1] + cnt[i-1][j+1][0])%mod;
                cnt[i][1][1] = (cnt[i][1][1] + cnt[i][j][1])%mod;
            }
        }
        long ans = 0;
        for (int i = 0; i <=k ; i++) {
            ans =  (ans + cnt[i][1][1] + cnt[i][n+1][0])%mod;

        }
        for (int i = 2; i <n+1 ; i++) {
            ans = (ans + cnt[1][i][0] +cnt[1][i][1])%mod;
        }
        out.println(ans);
    }


}
