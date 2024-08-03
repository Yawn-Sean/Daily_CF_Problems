import java.io.PrintWriter;
import java.util.Arrays;

public class cf989c_Leoncn {
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
        int a = sc.ni();
        int b = sc.ni();
        int c = sc.ni();
        int d = sc.ni();

        int n = 50;
        char[][] cs = new char[n][n];
        for(char[] s: cs){
            Arrays.fill(s,'Z');
        }
        a--;
        d--;
        for (int i = 0; i < n; i+=2) {
            for (int j = 0; j < n; j+=2) {
                if(a>0){
                    cs[i][j] = 'A';
                    a--;
                }else if(b>0){
                    cs[i][j] = 'B';
                    b--;
                }else if(c>0){
                    cs[i][j] = 'C';
                    c--;
                }
                if(c == 0){
                    break;
                }
            }
        }
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < n; j++) {
                if(cs[i][j] == 'Z'){
                    cs[i][j] = 'D';
                }

            }
        }


        for (int i = n-1; i >=0 ; i-=2) {
            for (int j = 0; j < n; j+=2) {
                if(d>0){
                    cs[i][j] = 'D';
                    d--;
                }
                if(d == 0){
                    break;
                }
            }
        }
        for (int i = 30; i <n ; i++) {
            for (int j = 0; j < n; j++) {
                if(cs[i][j] == 'Z'){
                    cs[i][j] = 'A';
                }
            }
        }
        out.println(n + " " + n);
        for (int i = 0; i < n; i++) {
            out.println(new String(cs[i]));
        }



    }
}
