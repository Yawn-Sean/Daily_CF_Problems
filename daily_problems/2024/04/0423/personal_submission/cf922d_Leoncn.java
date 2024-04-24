public class cf922d_Leoncn {
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
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.ns();
        }
        long[][] cnt = new long[n][2];
        long ans = 0;
        for (int i = 0; i < n; i++) {
            char[] cs = arr[i].toCharArray();
            for(char c: cs){
                if(c=='s'){
                    cnt[i][0]++;
                }else {
                    cnt[i][1] ++;
                    ans += cnt[i][0];
                }
            }
        }
        Arrays.sort(cnt, (a,b)->Long.compare(a[1]*b[0] , a[0]*b[1]));
        long s = 0;
        for (int i = 0; i < n; i++) {
            ans += cnt[i][1] *s;
            s += cnt[i][0];
        }
        out.println(ans);

    }

}
