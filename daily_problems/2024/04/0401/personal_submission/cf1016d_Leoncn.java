import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.util.InputMismatchException;

//https://codeforces.com/contest/1016/submission/254443573
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

    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int[] a = sc.na(n);
        int[] b = sc.na(m);
        int h = 0, k = 0;
        for (int i = 0; i < n; i++) {
            h^= a[i];
        }
        for (int i = 0; i < m; i++) {
            k^= b[i];
        }
        if(h!=k){
            out.println("NO");
            return;
        }

        int[][] ans = new int[n][m];
        int c = 0;
        for (int i = 1; i < m; i++) {
            ans[0][i] = b[i];
            c^=b[i];
        }
        for (int i = 1; i < n; i++) {
            ans[i][0] = a[i];
            //c^=a[i];
        }
        ans[0][0] = a[0]^c;
        out.println("YES");
        for(int[] f: ans){
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < m; i++) {
                sb.append(f[i]).append(" ");
            }
            out.println(sb);
        }
    }

}
