
public class cf1132c_Leoncn {
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
        int q = sc.ni();
        int[] cnt = new int[n];
        int[][] g = new int[q][2];
        for (int i = 0; i < q; i++) {
            int a = sc.ni()-1;
            int b = sc.ni()-1;
            g[i] = new int[]{a,b};
            for (int j = a; j <=b; j++) {
                cnt[j]++;
            }
        }
        int ans = 0;
        int[] pre = new int[n+1];
        for (int i = 1; i < q; i++) {

            int a = g[i][0];
            int b = g[i][1];
            for (int j = a; j <=b ; j++) {
                cnt[j]--;
            }
            int sum = 0;
            for (int j = 0; j < n; j++) {
                pre[j+1] = pre[j];
                if(cnt[j]>=1) {
                    sum++;
                }
                if(cnt[j] == 1){
                    pre[j+1]++;
                }
            }

            for (int j = 0; j < i; j++) {
                ans = Math.max(ans, sum - (pre[g[j][1] + 1] - pre[g[j][0]]));
            }
            for (int j = a; j <=b ; j++) {
                cnt[j]++;
            }
        }
        out.println(ans);
    }

}
