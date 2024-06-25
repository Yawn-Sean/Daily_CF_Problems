public class cf954c_Leoncn {
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
        int l = 1000000000;
        int d = -1;
        for (int i = 1; i < n; i++) {
            int w = Math.abs(g[i]-g[i-1]);
            if(w ==  1) continue;
            if(w == 0){
                out.println("NO");
                return;
            }
            d = w;
        }
        if(d == -1){
            d = 1000000000;
        }else {

            for (int i = 1; i < n; i++) {
                int x1 = (g[i-1]-1)/d ;
                int y1 = (g[i-1]-1)%d;

                int x2 = (g[i]-1)/d;
                int y2 = (g[i]-1)%d;
                if(Math.abs(x1-x2) + Math.abs(y1-y2)!=1){
                    out.println("NO");
                    return;
                }
            }
        }

        out.println("YES");
        out.println(l +" " +  d);
    }

}
