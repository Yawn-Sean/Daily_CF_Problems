import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
import java.util.InputMismatchException;

//https://codeforces.com/contest/870/submission/254859507
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
        int[] v1 = new int[n];
        int[] v2 = new int[n];

        for (int i = 0; i < n; i++) {
            v1[i] = query(i, 0);
        }

        v2[0] = v1[0];
        for (int i = 1; i < n; i++) {
            v2[i] = query(0, i);
        }
        int[] ans = null;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int[] p = new int[n];
            int[] b = new int[n];
            for (int j = 0; j < n; j++) {
                p[j] = -1;
                b[j] = -1;
            }

            p[0] = i;
            for (int j = 0; j < n; j++) {
                b[j] = v2[j] ^ p[0];
            }

            for (int j = 0; j < n; j++) {
                p[j] = v1[j] ^ b[0];
            }

            boolean valid = true;
            for (int j = 0; j < n; j++) {
                if (b[j] >= n || p[b[j]] != j) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans = p;
                cnt++;
            }

        }
        out.println("!");
        out.println(cnt);
        StringBuilder sb = new StringBuilder();
        for(int a: ans){
            sb.append(a).append(" ");
        }
        out.println(sb);

    }
    private static int query(int i, int j) {
        out.println("? " + i + " " + j);
        out.flush();
        return sc.ni();
    }
}