import java.io.PrintWriter;

public class cf301a_Leoncn {
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
        int[] g = sc.na(2*n-1);
        int min = 10000;
        int c = 0;
        int z = 0;
        int ans = 0;
        for (int i = 0; i < 2*n-1; i++) {
            if(g[i]<0){
                c++;

            }else if(g[i] == 0){
                z++;
            }
            min = Math.min(min, Math.abs(g[i]));
            ans += Math.abs(g[i]);
        }
        if(z==0 && ((c%n) &1)==1 && ((n-c%n)&1)==1){
            ans -= 2*min;
        }
        out.println(ans);
    }    
}
