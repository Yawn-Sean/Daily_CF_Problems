public class cf1020c_Leoncn {
    
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
        String s = sc.ns();
        s += s;
        int n = s.length();
        char[] cs = s.toCharArray();
        int c = 1, ans = 1;
        for (int i = 1; i < n; i++) {
            if(cs[i]!=cs[i-1]){
                c++;
            }else {
                c = 1;
            }
            ans = Math.max(c, ans);
        }
        out.println(Math.min(ans,n/2));

    }
}
