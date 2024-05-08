import java.io.PrintWriter;

public class cf1644e_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = sc.ni();
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    public static void solve() {
        long n = sc.nl();
        char[] cs = sc.ns().toCharArray();
        long ans = 0;
        int f = -1;
        for (int i = 0; i < cs.length; i++) {
            if(cs[i]!=cs[0]){
                f = i;
                break;
            }
        }
        if(f == -1){
            out.println(n);
            return;
        }
        ans = f + (n-f)*n;
        long a = 0, b =0;
        for (int i = f; i < cs.length; i++) {
            if(cs[i] == 'R'){
                a++;
            }else {
                b++;
            }
        }
        out.println(ans - a*b);
    } 
}
