public class cf336d_Leoncn {
    static int mod = (int)1e9+7;
    static Combitation com;
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int g = sc.ni();
        com = new Combitation(m+n+1, mod);
        long ans = 0;
        if(m == 0){
            ans = g ==((n-1)&1)?1:0;
        }else {
            int cur = 0;
            for (int i = 0; i <= n; i++) {
                if(i == n && m==1){
                    cur = 1 - cur;
                }
                if(cur == g){
                    ans = (ans + com.comb(m+n-i-1, n-i))%mod;
                }
                cur = 1 - cur;

            }
        }
        out.println(ans);
    }
}
