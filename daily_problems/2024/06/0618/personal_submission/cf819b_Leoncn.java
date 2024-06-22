public class cf819b_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] g = new int[n+1];
        long now = 0;

        int[] cnt = new int[n];
        int l = 0, r = 0;
        for (int i = 1; i <=n; i++) {
            g[i] = sc.ni();
            int idx = (g[i] -i + n)%n;
            cnt[idx]++;
            now += Math.abs(g[i] -i);
            int b = g[i] - i;
            if(b<=0){
                l++;
            }else {
                r++;
            }
        }

        long ans = now, res = 0;
        for (int i = 1; i <n ; i++) {
            int x = g[n-i+1];
            now = now + l-1 - r - (n-x) + x-1;
            l = l - 1 + cnt[i];
            r = n- l;
            if(ans > now){
                ans = now;
                res = i;
            }
        }
        out.print(ans + " " + res);
    }
}
