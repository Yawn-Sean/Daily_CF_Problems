public class cf500d_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    static BigDecimal sum;
    static long[] c;
    static int n;
    static ArrayList<int[]>[] g;
    static long[] tot;
    public static void solve() {
        n = sc.ni();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        c = new long[n-1];
        tot = new long[n-1];
        for (int i = 0; i < n-1; i++) {
            int a = sc.ni() - 1;
            int b = sc.ni() - 1;
            int w = sc.ni();
            c[i] = w;
            g[a].add(new int[]{b, i});
            g[b].add(new int[]{a, i});
        }
        sum = new BigDecimal("0");
        dfs(0,-1);

        int q = sc.ni();
        while (q-->0){
            int a = sc.ni() - 1;
            int w = sc.ni();

            sum = sum.add(BigDecimal.valueOf(w *2*tot[a]- c[a] *2*tot[a]));
            double ans = sum .multiply(BigDecimal.valueOf(6)).divide (BigDecimal.valueOf((long)n*(n-1)*(n-2)), 10,RoundingMode.HALF_UP).doubleValue();
            c[a] = w;
            out.println(ans);
        }
    }
    private static long dfs(int cur, int p ){
        long cnt = 1;
        for(int[] w: g[cur]){
            if(w[0] == p) continue;
            long c1 = dfs(w[0], cur);
            long c2 = n-c1;
            long total = c1*(c2-1)*c2/2 + c2*c1*(c1-1)/2;
            sum = sum.add(BigDecimal.valueOf(c[w[1]] *2 * total));
            tot[w[1]] = total;
            cnt += c1;
        }
        return cnt;
    }
}
