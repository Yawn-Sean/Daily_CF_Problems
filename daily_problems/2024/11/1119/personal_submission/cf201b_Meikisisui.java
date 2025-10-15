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
        long[][] c = new long[n][m];
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(f.readLine());
            for (int vn = 0; vn < m; vn++)
                c[ez][vn] = Long.parseLong(st.nextToken());
        }
        // 任意一点到每个车距离为dx^2+dy^2
        // 所以它到每行的dy一样，到每列的dx一样
        // 所以它的总距离，等于它前边的行前缀和+前边的列前缀和+后边的行后缀和+后边的列后缀和
        long[] preR = new long[n], backR = new long[n + 1], preC = new long[m], backC = new long[m + 1];
        long[] sumC = new long[m], sumR = new long[n];
        long res = Long.MAX_VALUE;
        for (int vn = m - 1; vn >= 0; vn--) {
            for (int ez = 0; ez < n; ez++)
                sumC[vn] += c[ez][vn];
            for (int ks = vn, d = 2; ks < m; ks++, d += 4)
                backC[vn] += d * d * sumC[ks];
        }
        for (int ez = n - 1; ez >= 0; ez--) {
            for (int vn = 0; vn < m; vn++)
                sumR[ez] += c[ez][vn];
            for (int ks = ez, d = 2; ks < n; ks++, d += 4)
                backR[ez] += d * d * sumR[ks];
        }
        for (int ez = 0; ez < n; ez++) {
            for (int ks = ez, d = 2; ks >= 0; ks--, d += 4)
                preR[ez] += d * d * sumR[ks];
        }
        for (int vn = 0; vn < m; vn++) {
            for (int ks = vn, d = 2; ks >= 0; ks--, d += 4)
                preC[vn] += d * d * sumC[ks];
        }
        long resX = -1, resY = -1;
        for (int ez = 0; ez <= n; ez++)
            for (int vn = 0; vn <= m; vn++) {
                long curr = backC[vn];
                if (vn > 0)
                    curr += preC[vn - 1];
                curr += backR[ez];
                if (ez > 0)
                    curr += preR[ez - 1];
                if (curr < res) {
                    res = curr;
                    resX = ez;
                    resY = vn;
                }
            }
        pw.println(res);
        pw.println(resX + " " + resY);
        pw.close();
        f.close();
    }

}
