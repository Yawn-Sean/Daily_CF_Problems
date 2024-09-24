import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        String str = st.nextToken();
        st = new StringTokenizer(f.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int res = getMinChange(n, str, x, y);
        pw.println(res);
        pw.close();
        f.close();
    }

    private static int getMinChange(int n, String str, int x, int y) {
        if (Math.abs(x) + Math.abs(y) > n || (n - Math.abs(x) - Math.abs(y)) % 2 != 0)
            return -1;
        int[] sl = new int[n + 1];
        int[] sr = new int[n + 1];
        int[] su = new int[n + 1];
        int[] sd = new int[n + 1];
        // 想给弄成一次遍历结果没搞出来
        for (int i = 1; i <= n; i++) {
            if (str.charAt(i - 1) == 'L')
                sl[i]++;
            if (str.charAt(i - 1) == 'R')
                sr[i]++;
            if (str.charAt(i - 1) == 'U')
                su[i]++;
            if (str.charAt(i - 1) == 'D')
                sd[i]++;
        }
        for (int i = 1; i <= n; i++) {
            sl[i] += sl[i - 1];
            sr[i] += sr[i - 1];
            su[i] += su[i - 1];
            sd[i] += sd[i - 1];
        }
        int l = 0, r = 1, res = Integer.MAX_VALUE;
        if (sr[n] - sl[n] == x && su[n] - sd[n] == y)
            res = 0;
        // 双指针
        // 若 [L,R] 不是答案，那么 [L + 1,R] 到 [R - 1,R] 一定也不是答案
        // 若 [L,R] 是答案，那么 [L + 1,R] 到 [R - 1,R] 可能也是答案
        for (r = 1; r <= n; r++) {
            int nx = sr[n] - sr[r] + sr[l];
            nx -= sl[n] - sl[r] + sl[l];
            int ny = su[n] - su[r] + su[l];
            ny -= sd[n] - sd[r] + sd[l];
            int d = Math.abs(nx - x) + Math.abs(ny - y);
            int len = r - l;
            while (l < r && len >= d) {
                res = Math.min(res, len);
                l++;
                nx = sr[n] - sr[r] + sr[l];
                nx -= sl[n] - sl[r] + sl[l];
                ny = su[n] - su[r] + su[l];
                ny -= sd[n] - sd[r] + sd[l];
                d = Math.abs(nx - x) + Math.abs(ny - y);
                len = r - l;
            }
        }
        return res;
    }

}
