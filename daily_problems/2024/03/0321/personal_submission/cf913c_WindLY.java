import java.util.*;
import java.io.*;
public class cf913c_WindLY {
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        int[] in = na();
        int n = in[0], x = in[1];
        int[] a = na();
        for (int i = 0; i < n - 1; i++) {
            a[i + 1] = Math.min(a[i + 1], a[i] << 1);
        }
        long ans = Long.MAX_VALUE;
        long cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            int v = 1 << i;
            ans = Math.min(ans, cur + (long) (x + v - 1) / v * a[i]);
            cur += (long) x / v * a[i];
            x %= v;
        }
        out.println(ans);
        out.flush();
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