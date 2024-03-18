import java.util.*;
import java.io.*;
public class cf772b_WindLY {
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        int n = ni();
        int[][] p = new int[n][2];
        for (int i = 0; i < n; i++) {
            p[i] = na();
        }
        double ans = Double.MAX_VALUE;
        for (int i = 0; i < n; i++) { // 在三个点作圆，求三个圆相切一条直线的半径
            int x1, y1, x2 = p[i][0], y2 = p[i][1], x3, y3;
            x1 = i == 0 ? p[n - 1][0] : p[i - 1][0];
            y1 = i == 0 ? p[n - 1][1] : p[i - 1][1];
            x3 = i == n - 1 ? p[0][0] : p[i + 1][0];
            y3 = i == n - 1 ? p[0][1] : p[i + 1][1];
            double v = f(x1, y1, x2, y2, x3, y3);
            ans = Math.min(ans, v);
        }
        out.println(ans);
        out.flush();
    }
    static double f(double x1, double y1, double x2, double y2, double x3, double y3) {
        double v = 0;
        // y = kx + b
        if (x1 == x3) {
            return Math.abs(x2 - x1) / 2;
        }
        double k = (y3 - y1) / (x3 - x1), b = y3 - k * x3;
        double d = Math.abs(k * x2 - y2 + b) / Math.sqrt(1 + k * k);
        return d / 2;
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