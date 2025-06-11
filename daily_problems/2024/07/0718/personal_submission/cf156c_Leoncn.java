
public class cf156c_Leoncn {
    static int[][] dp;
    static int mod = (int)1e9+7;
    static {
        dp = new int[110][110*26];
        dp[0][0] = 1;
        for (int i = 1; i <=100 ; i++) {
            for (int j = i; j <= 26*i ; j++) {
                for (int k = 1; k <= 26; k++) {
                    if(j-k>=0){
                        dp[i][j] = (dp[i][j]  + dp[i-1][j-k])%mod;
                    }
                }
            }
        }
    }

    public static void solve() {
        char[] cs = sc.ns().toCharArray();
        int n = cs.length;
        int s = 0;
        for(char c: cs){
            s += c-'a' +1;
        }
        out.println((dp[n][s] - 1 + mod)%mod );

    }
}
