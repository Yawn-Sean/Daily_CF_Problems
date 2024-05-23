

public class cf900c_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }

        out.close();
    }

    public static void solve() {
        int n = sc.ni();
        int[] g = sc.na(n);
        int[] cnt = new int[n+1];
        int ma1 = -1, ma2 = -1;
        for (int i = 0; i <n ; i++) {
            if(g[i]>ma1){
                cnt[g[i]]--;

                ma2 = ma1;
                ma1 = g[i];
            }else if(g[i]>ma2){
                cnt[ma1]++;
                ma2 = g[i];
            }
        }
        int res = -n-1;
        int ans = 0;
        for (int i = 1; i <=n ; i++) {
            if(cnt[i]>res){
                res = cnt[i];
                ans = i;
            }
        }
        out.println(ans);
    }
}
