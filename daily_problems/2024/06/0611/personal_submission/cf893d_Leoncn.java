public class cf893d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int d = sc.ni();
        int[] g = sc.na(n);
        int ans = 0;
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            if(g[i] == 0){
                l = Math.max(l, 0);
                if(r<0){
                    r = d;
                    ans++;
                }
            }else {
                l += g[i];
                r += g[i];
                r = Math.min(r, d);
                if(l>d){
                    out.println(-1);
                    return;
                }
            }
        }
        out.println(ans);
    }    
}
