
public class cf533e_Leoncn {
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
        String s = sc.ns();
        String t = sc.ns();
        char[] cs = s.toCharArray();
        char[] tar = t.toCharArray();
        int l = -1, r = -1;
        int c = 0;
        for (int i = 0; i < n; i++) {
            if(cs[i] != tar[i]){
                if(l == -1){
                    l = i;
                }else {
                    r = i;
                }
                c++;
            }
        }
//        if(c>2){
//            out.println(0);
//            return;
//        }
        if(c == 1){
            out.println(2);
            return;
        }

        int ans = s.substring(l,r).equals(t.substring(l+1, r+1))?1:0;
        ans += s.substring(l+1,r+1).equals(t.substring(l, r))?1:0;
        out.println(ans); 
}
