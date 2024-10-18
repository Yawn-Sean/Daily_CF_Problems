public class cf847h_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] g = sc.na(n);
        long[] suf = new long[n];
        int[] q = new int[n];
        for (int i = n-1; i >=0 ; i--) {
            if(i == n-1){
                q[i] = g[i];
            }else {
                q[i] = Math.max(g[i],q[i+1]+1);
                suf[i] = suf[i+1] + q[i] - g[i];
            }
        }
        long ans = suf[0];
        long pre = 0;
        int f = g[0];
        for (int i = 1; i < n; i++) {
            f = Math.max(g[i],f+1);
            ans = Math.min(ans, Math.max(f, q[i]) - g[i] + (i==n-1?0:suf[i+1]) + pre);
            pre = pre + f- g[i];
        }
        out.println(ans);

    }
}
