public class cf340e_Leoncn {
    static int mod = 1000000007;
    static Combitation combitation = new Combitation(2001,mod);
    public static void solve() {
        int n = sc.ni();
        int[] g = sc.na(n);
        int[] used = new int[n];
        for (int i = 0; i < n; i++) {
            int f = g[i] - 1;
            if(f>=0){
                used[f] = 1;
            }
        }
        int x1 = 0, x0 = 0;
        for (int i = 0; i < n; i++) {
            if(used[i] == 0){
                if(g[i]<0){
                    x0++;
                }else {
                    x1++;
                }
            }
        }
        long ans = 0;
        long cur = 1;
        for (int i = 0; i < x0+1; i++) {
            ans = (ans + cur * Combitation.fac[x0 + x1 - i]  %mod* combitation.comb(x0, i)) %mod;
            cur = -cur;
        }
        out.println((ans + mod)%mod);
        
    }
}
