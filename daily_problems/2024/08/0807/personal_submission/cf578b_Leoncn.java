
public class cf578b_Leoncn {
    public static void solve() {
        int n = sc.ni(), k = sc.ni(),  x= sc.ni();
        int[] g = sc.na(n);
        long p = (long)Math.pow(x, k);
        long[] suf = new long[n+1];
        for (int i = n-1; i >=0 ; i--) {
            suf[i] = suf[i+1] | g[i];
        }
        long ans = 0;
        long pre = 0;
        for (int i = 0; i <n ; i++) {
            ans = Math.max(pre | p * g[i] | suf[i+1], ans );
            pre |= g[i];
        }
        out.println(ans);
    }

}
