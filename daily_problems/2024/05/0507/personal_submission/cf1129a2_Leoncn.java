public class cf1129a2_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);


    public static void main(String[] args) {
        int t = 1;
        while (t-->0){
            solve();
        }
        out.close();

    }

    public static void solve(){
        int n = sc.ni();
        int m = sc.ni();
        int[] cnt = new int[n];
        int[] dest = new int[n];
        Arrays.fill(dest, n+1);
        for (int i = 0; i < m; i++) {
            int a = sc.ni()-1;
            int b = sc.ni()-1;
            cnt[a]++;
            dest[a] = Math.min(dest[a], (n+b-a)%n);
        }
        for (int i = 0; i < n; i++) {
            int ans = 0;
            for (int j = i; j <i+n ; j++) {
                int f = j%n;
                if(dest[f]!=n+1){
                    ans = Math.max((cnt[f]-1)*n + dest[f] + j- i, ans);
                }

            }
            out.print(ans + " ");
        }
    }

}
