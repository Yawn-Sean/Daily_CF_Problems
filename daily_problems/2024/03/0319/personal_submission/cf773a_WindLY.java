import java.util.*;
import java.io.*;
public class cf773a_WindLY {
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        int t = ni();
        while (t-- > 0) {
            int[] in = na();
            long ans = solve(in);
            if (ans == Integer.MAX_VALUE / 2 + 1) ans = -1;
            else {
                ans = ans * in[3] - in[1];
            }
            out.println(ans);
        }
        out.flush();
    }
    static long solve(int[] in) {
        int x = in[0], y = in[1], p = in[2], q = in[3];
        int l = 0, r = Integer.MAX_VALUE / 2;
        while (l <= r) {
            int m = l + r >> 1;
            if (check(m, x, y, p, q)) r = m - 1;
            else l = m + 1;
        }
        return l;
    }
    static boolean check(int a, long x, long y, long p, long q) {
        q *= a;
        p *= a;
        return p - x >= 0 && q - y >= p - x;
    }
    static int ni() throws IOException {
        return Integer.parseInt(sc.readLine());
    }
    static int[] na() throws IOException {
        String[] in = sc.readLine().split(" ");
        int[] a = new int[in.length];
        for (int i = 0; i < in.length; i++) {
            a[i] = Integer.parseInt(in[i]);
        }
        return a;
    }
}
