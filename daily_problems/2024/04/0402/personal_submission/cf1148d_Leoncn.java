import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.util.InputMismatchException;

public class D {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    //https://codeforces.com/contest/1148/submission/254714424
    public static void solve() {
        int n = sc.ni();
        int[][] g = new int[n][3];
        for (int i = 0; i < n; i++) {
            g[i][0] = sc.ni();
            g[i][1] = sc.ni();
            g[i][2] = i+1;
        }
        Arrays.sort(g,(a,b)->a[1]-b[1]);
        StringBuilder sb = new StringBuilder();
        StringBuilder sb2 = new StringBuilder();
        int c = 0;
        for (int i = 0; i < n; i++) {
            if(g[i][0]>g[i][1]){
                sb.append(g[i][2]).append(" ");
                c++;
            }
        }
        for (int i = n-1; i >=0 ; i--) {
            if(g[i][0]<g[i][1]){
                sb2.append(g[i][2]).append(" ");
            }
        }
        if(c>= n-c){
            out.println(c);
            out.println(sb);
        }else {
            out.println(n-c);
            out.println(sb2);
        }
    }
}
