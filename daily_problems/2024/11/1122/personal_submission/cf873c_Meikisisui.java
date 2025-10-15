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
        int k = Integer.parseInt(st.nextToken());
        int[][] matrix = new int[n + 1][m + 1];
        for (int ez = 1; ez <= n; ez++) {
            st = new StringTokenizer(f.readLine());
            for (int vn = 1; vn <= m; vn++)
                matrix[ez][vn] = Integer.parseInt(st.nextToken());
        }
        int[] sum = new int[n + 2];
        int res = 0, score = 0;
        for (int vn = 1; vn <= m; vn++) {
            int hang = 0, tmp = 0;
            for (int ez = n; ez >= 1; ez--)
                sum[ez] = sum[ez + 1] + matrix[ez][vn];
            for (int ez = n; ez >= 1; ez--) {
                if (matrix[ez][vn] != 0 && sum[ez] - sum[Math.min(ez + k, n + 1)] >= tmp) {
                    tmp = sum[ez] - sum[Math.min(ez + k, n + 1)];
                    hang = ez;
                }
            }
            res += sum[1] - sum[hang];
            score += tmp;
        }
        pw.println(score + " " + res);
        pw.close();
        f.close();
    }

}
