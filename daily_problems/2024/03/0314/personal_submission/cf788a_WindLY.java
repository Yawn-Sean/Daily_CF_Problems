import java.util.*;
import java.io.*;
public class cf788a_WindLY {
    // 贪心双指针
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        int n = ni();
        int[] in = na();
        int[] a = new int[n], b = new int[n];
        // a第一个为负  b第一个为正  在两个情况中贪心取子数组最大和
        for (int i = 0; i < n - 1; i++) {
            a[i] = Math.abs(in[i] - in[i + 1]);
            if (i % 2 == 0) a[i] = -a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            b[i] = Math.abs(in[i] - in[i + 1]);
            if (i % 2 == 1) b[i] = -b[i];
        }
        long ans = Math.max(find(a), find(b));
        out.println(ans);
        out.flush();
    }
    // 取到的子数组第一个必然为正数，第一个为负数的情况贪心已经剔除
    static long find(int[] a) {
        long sum = 0, max = Long.MIN_VALUE;
        boolean f = false;
        for (int v: a) {
            max = Math.max(max, v);
            if (sum + v < 0) {
                if (f) max = Math.max(max, sum);
                sum = 0;
                f = false;
            } else {
                sum += v;
                f = true;
                max = Math.max(max, sum);
            }
        }
        return max;
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
