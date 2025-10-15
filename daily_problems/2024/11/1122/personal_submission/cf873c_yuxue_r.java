import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int k = scanner.nextInt();

        int[][] grid = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = scanner.nextInt();
            }
        }
        int ans = 0, cnt = 0;
        int[] acc = new int[n + 1];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                acc[j + 1] = acc[j] + grid[j][i];
            }

            int res = 0, chosen_idx = 0;
            for (int j = 0; j < n; j++) {
                if (grid[j][i] != 0) {
                    int v = acc[Math.min(j + k, n)] - acc[j];
                    if (v > res) {
                        res = v;
                        chosen_idx = acc[j];
                    }
                }
            }
            ans += res;
            cnt += chosen_idx;
        }

        System.out.println(ans + " " + cnt);
    }
}
