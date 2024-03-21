import java.util.*;
import java.io.*;
public class cf863d_WindLY {
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        int[] in = na();
        int n = in[0], q = in[1], m = in[2];
        int[] a = na();
        int[][] query = new int[q][3];
        for (int i = 0; i < q; i++) {
            query[i] = na();
        }
        int[] b = na();
        for (int i = 0; i < m; i++) {
            f(b[i] - 1, a, query);
        }
        out.flush();
    }
    static void f(int i, int[] a, int[][] query) {
        int n = a.length, m = query.length;
        for (int j = m - 1; j >= 0; j--) {
            int[] q = query[j];
            int l = q[1] - 1, r = q[2] - 1;
            if (q[0] == 1) { // move left
                if (i == l) i = r;
                else if (i >= l && i <= r) i--;
            } else {
                if (i >= l && i <= r) {
                    int len = i - l;
                    i = r - len;
                }
            }
        }
        out.print(a[i] + " ");
    }
    static int ni() throws IOException {
        return Integer.parseInt(sc.readLine());
    }
    static int[] na() throws IOException {
        String[] in = sc.readLine().split(" ");
        int n = in.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = Integer.parseInt(in[i]);
        }
        return ans;
    }
}