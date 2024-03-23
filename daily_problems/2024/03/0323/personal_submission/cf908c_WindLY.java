import java.io.*;

public class cf908c_WindLY {
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        int[] in = na();
        int n = in[0];
        double ri = in[1];
        int[] a = na();
        double[] ay = new double[n];
        for (int i = 0; i < n; i++) {
            double x = a[i], y = ri;
            for (int j = 0; j < i; j++) {
                y = Math.max(y, f(x, a[j], ay[j], ri));
            }
            ay[i] = y;
        }
        for (double v: ay) out.print(v + " ");
        out.flush();
    }
    static double f(double x, double x2, double y, double ri) {
        double xx = Math.abs(x2 - x);
        if (xx > 2 * ri) return 0;
        ri *= 2;
        return y + Math.sqrt(ri * ri - xx * xx);
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
