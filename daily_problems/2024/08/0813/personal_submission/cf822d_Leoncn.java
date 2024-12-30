
public class cf822d_Leoncn {
    public static void solve() {
        int t = sc.ni();
        int l = sc.ni();
        int r = sc.ni();
        int max = (int)5e6+1;
        int mod = (int)1e9+7;
        int[] p = new int[max];
        for (int i = 0; i < max; i++) {
            p[i] = i;
        }
        for (int i = 2; i <3e3+1 ; i++) {
            if(p[i] == i ){
                for (int j = i*i; j <max ; j+=i) {
                    if(p[j] == j){
                        p[j] = i;
                    }
                }
            }
        }
        long[] dp = new long[max];
        for (int i = 2; i <max ; i++) {
            int f = p[i];
            dp[i] = (dp[i/f] + (long) i * (f-1)/2)%mod;
        }
        long ans = 0;
        for (int i = r; i >=l ; i--) {
            ans = (ans * t + dp[i])%mod;
        }
        out.println(ans);
    }

}
