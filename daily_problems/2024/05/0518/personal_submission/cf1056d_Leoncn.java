public class cf1056d_Leoncn {
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
        if(n==1){
            out.println(1);
            return;
        }
        int[] g = new int[n];
        for (int i = 1; i <n; i++) {
            g[i] = sc.ni() -1;
        }
        g[0] = -1;
        int[] cnt = new int[n];
        for (int i = n-1; i >0 ; i--) {
            if(cnt[i] == 0){
                cnt[i] = 1;
            }
            cnt[g[i]] += cnt[i];
        }
        Arrays.sort(cnt);
        for(int c: cnt){
            out.print(c + " ");
        }
    }
}
