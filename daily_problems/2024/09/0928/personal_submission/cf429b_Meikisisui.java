import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] nums = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(f.readLine());
            for (int j = 1; j <= m; j++)
                nums[i][j] = Integer.parseInt(st.nextToken());
        }
        int[][] dp11 = new int[n + 2][m + 2];
        int[][] dp12 = new int[n + 2][m + 2];
        int[][] dp21 = new int[n + 2][m + 2];
        int[][] dp22 = new int[n + 2][m + 2];
        for (int y1 = 1; y1 <= n; y1++) {
            for (int x1 = 1; x1 <= m; x1++) {
                int y2 = n - y1 + 1;
                int x2 = m - x1 + 1;
                dp11[y1][x1] = Math.max(dp11[y1 - 1][x1], dp11[y1][x1 - 1]) + nums[y1][x1];
                dp12[y2][x2] = Math.max(dp12[y2 + 1][x2], dp12[y2][x2 + 1]) + nums[y2][x2];
                dp21[y2][x1] = Math.max(dp21[y2 + 1][x1], dp21[y2][x1 - 1]) + nums[y2][x1];
                dp22[y1][x2] = Math.max(dp22[y1 - 1][x2], dp22[y1][x2 + 1]) + nums[y1][x2];
            }
        }
        int res = 0;
        for (int i = 2; i < n; i++) {
            for (int j = 2; j < m; j++)
                res = Math.max(res, Math.max(dp11[i][j - 1] + dp21[i + 1][j] + dp12[i][j + 1] + dp22[i - 1][j],
                        dp11[i - 1][j] + dp12[i + 1][j] + dp21[i][j - 1] + dp22[i][j + 1]));
        }
        pw.println(res);
        pw.close();
        f.close();
    }

}
