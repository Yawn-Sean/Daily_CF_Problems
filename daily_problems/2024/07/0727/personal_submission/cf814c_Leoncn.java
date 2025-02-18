
public class cf814c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        char[] cs = sc.ns().toCharArray();
        int q = sc.ni();
        int[] g = new int[n];
        for (int i = 0; i < n; i++) {
            g[i] = cs[i] -'a';
        }
        int[][] dp = new int[26][n+1];
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <=n ; j++) {
                int l = 0;
                int cnt = 0;
                for (int k = 0; k < n; k++) {
                    if(g[k]!=i){
                        cnt++;
                    }
                    while (cnt>j){
                        if(g[l] != i){
                            cnt--;
                        }
                        l++;
                    }
                    dp[i][j] = Math.max(dp[i][j], k-l+1);
                }
            }
        }
        for (int i = 0; i < q; i++) {
            int a = sc.ni();
            int c = sc.nc() - 'a';
            out.println(dp[c][a]);
        }
    }
}
