public class cf863e_Leoncn {
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
        int[][] g = new int[n][3];
        for (int i = 0; i < n; i++) {
            g[i][0] = sc.ni();
            g[i][1] = sc.ni();
            g[i][2] = i;
        }
        Arrays.sort(g,(a,b)->{
            if(a[0] == b[0]){
                return b[1] - a[1];
            }
            return a[0] - b[0];
        });
        int a = -1, b = -1;
        for (int i = 0; i < n; i++) {
            if(a>=0 &&  g[a][1] >= g[i][1]){
                out.println(g[i][2] + 1);
                return;
            }
            if(b>=0 && g[b][1]+1>=g[i][0]){
                out.println(g[a][2]+1);
                return;
            }
            b = a;
            a = i;
        }
        out.println(-1);

    }

}
