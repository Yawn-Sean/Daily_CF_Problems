import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        boolean[] px = new boolean[n];
        boolean[] py = new boolean[n];
        for (int ez = 0; ez < m; ez++) {
            st = new StringTokenizer(f.readLine());
            int r = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken()) - 1;
            px[r] = true;
            py[c] = true;
        }
        int a = 0, b = 0;
        for (int ez = 0; ez < n; ez++) {
            if (px[ez])
                a++;
            if (py[ez])
                b++;
        }
        double[][] dp = new double[n + 2][n + 2];
        dp[n][n] = 0;
        for (int ez = n; ez >= a; ez--) {
            for (int vn = n; vn >= b; vn--) {
                if (ez == n && vn == n)
                    continue;
                double gx = ez / (double) n;
                double gy = vn / (double) n;
                dp[ez][vn] = ((1 - gx) * (1 - gy) * (dp[ez + 1][vn + 1] + 1)
                        + (1 - gx) * gy * (dp[ez + 1][vn] + 1)
                        + gx * (1 - gy) * (dp[ez][vn + 1] + 1)
                        + gx * gy) / (1 - gx * gy);
            }
        }
        pw.println(dp[a][b]);
        pw.close();
        f.close();
    }

}
