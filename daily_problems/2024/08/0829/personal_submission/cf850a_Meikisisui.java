import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    private static int[][] a;
    private static int[] res;
    private static int[] x;
    private static int[] y;
    private static final double pi = 3.14159265;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        // 就不写注释了猜的无法证明
        if (n > 11) {
            pw.println(0);
            pw.close();
            f.close();
            return;
        }
        a = new int[n][5];
        res = new int[1005];
        x = new int[1005];
        y = new int[1005];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(f.readLine());
            for (int j = 0; j < 5; j++)
                a[i][j] = Integer.parseInt(st.nextToken());
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            boolean flag = true;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    for (int k = j + 1; k < n; k++) {
                        if (j != k && i != k) {
                            double p = jiao(k, j, i);
                            if (p < 90)
                                flag = false;
                        }
                    }
                }
            }
            if (flag)
                res[cnt++] = i + 1;
        }
        pw.println(cnt);
        for (int i = 0; i < cnt; i++)
            pw.println(res[i]);
        pw.close();
        f.close();
    }

    private static double jiao(int e, int r, int t) {
        int xy = 0;
        int X = 0, Y = 0;
        for (int i = 0; i < 5; i++) {
            x[i] = a[e][i] - a[t][i];
            y[i] = a[r][i] - a[t][i];
            xy += x[i] * y[i];
            X += x[i] * x[i];
            Y += y[i] * y[i];
        }
        X = (int) Math.sqrt(X);
        Y = (int) Math.sqrt(Y);
        double yx = (double) xy / (X * Y);
        if (yx >= -1 && yx <= 1) {
            yx = Math.acos(yx);
            return (yx / pi) * 180;
        } else
            return 0;
    }

}
