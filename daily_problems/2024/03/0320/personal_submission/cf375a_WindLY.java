import java.util.*;
import java.io.*;
public class cf375a_WindLY {
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        String s = sc.readLine();
        int[] a = new int[7];
        build(a, 0, 0, new boolean[4]);
        int[] cnt = new int[10];
        for (int i = 0; i < s.length(); i++) {
            int c = s.charAt(i) - '0';
            cnt[c]++;
        }
        cnt[1]--;
        cnt[6]--;
        cnt[8]--;
        cnt[9]--;
        if (cnt[0] == s.length() - 4) {
            StringBuilder sb = new StringBuilder();
            sb.append(1869);
            while (cnt[0]-- > 0) sb.append(0);
            out.println(sb);
        } else {
            int cur = 0;
            StringBuilder sb = new StringBuilder();
            for (int i = 9; i >= 0; i--) {
                while (cnt[i]-- > 0) {
                    cur = (cur * 10 + i) % 7;
                    sb.append(i);
                }
            }
            cur = (cur * 10000) % 7;
            sb.append(a[(7 - cur) % 7]);
            out.println(sb);
        }
        out.flush();
    }
    static int[] nums = {1, 6, 8, 9};
    static void build(int[] a, int cur, int cnt, boolean[] vis) {
        if (cnt == 4) {
            int m = cur % 7;
            if (a[m] == 0) a[m] = cur;
            return;
        }
        for (int j = 0; j < 4; j++) {
            if (vis[j]) continue;
            vis[j] = true;
            build(a, cur * 10 + nums[j], cnt + 1, vis);
            vis[j] = false;
        }
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
