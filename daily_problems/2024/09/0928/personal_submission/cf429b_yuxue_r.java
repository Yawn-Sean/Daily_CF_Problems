import java.util.*;
import java.io.*;

public class cf429b {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] grid = new int[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                grid[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int[][] dp0 = new int[n][m];
        int[][] dp1 = new int[n][m];
        int[][] dp2 = new int[n][m];
        int[][] dp3 = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = 0;
                if (i > 0) x = Math.max(x, dp0[i - 1][j]);
                if (j > 0) x = Math.max(x, dp0[i][j - 1]);
                dp0[i][j] = x + grid[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                int x = 0;
                if (i > 0) x = Math.max(x, dp1[i - 1][j]);
                if (j < m - 1) x = Math.max(x, dp1[i][j + 1]);
                dp1[i][j] = x + grid[i][j];
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                int x = 0;
                if (i < n - 1) x = Math.max(x, dp2[i + 1][j]);
                if (j > 0) x = Math.max(x, dp2[i][j - 1]);
                dp2[i][j] = x + grid[i][j];
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int x = 0;
                if (i < n - 1) x = Math.max(x, dp3[i + 1][j]);
                if (j < m - 1) x = Math.max(x, dp3[i][j + 1]);
                dp3[i][j] = x + grid[i][j];
            }
        }

        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                ans = Math.max(ans, dp0[i - 1][j] + dp1[i][j + 1] + dp2[i][j - 1] + dp3[i + 1][j]);
                ans = Math.max(ans, dp0[i][j - 1] + dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j + 1]);
            }
        }
        System.out.println(ans);
    }
}
