import java.util.*;
import java.io.*;
public class cf566f_WindLY {
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        int n = ni();
        int mv = (int) 1e6;
        int[] a = new int[mv + 1];
        for (int i: na()) a[i]++;
        int[] dp = new int[mv + 1];
        for (int i = 1; i < mv + 1; i++) {
            dp[i] += a[i];
            for (int j = i; j < mv + 1; j += i) {
                dp[j] = Math.max(dp[j], dp[i]);
            }
        }
        int ans = 0;
        for (int i: dp) ans = Math.max(ans, i);
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
