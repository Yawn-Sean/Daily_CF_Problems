import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();

            int[][] grid = new int[n][m];

            for (int i = 0; i < n; i++) {
                String s = sc.next();
                for (int j = 0; j < m; j++) {
                    grid[i][j] = s.charAt(j) - '0';
                }
            }
            int ans = n * m;
            int[] cnt = new int[m];
            int[] calc = new int[m];
            for (int i = 0; i <= n - 5; i++) {
                for (int j = 0; j < m; j++)
                    cnt[j] = 0;
                
                for (int j = i + 1; j < i + 4; j++)
                    for (int k = 0; k < m; k++)
                        cnt[k] += grid[j][k];
                
                for (int j = i + 4; j < n; j++) {
                    for (int k = 0; k < m; k++)
                        calc[k] = cnt[k];
                    for (int k = 1; k < m; k++)
                        calc[k] += 2 - grid[i][k] - grid[j][k];
                    for (int k = 1; k < m; k++)
                        calc[k] += calc[k - 1];
                    int cur = n * m;
                    for (int k = m - 1; k >= 3; k--) {
                        cur = Math.min(cur, calc[k - 1] + j - i - 1 - cnt[k]);
                        ans = Math.min(ans, cur - calc[k - 3] + j - i - 1 - cnt[k - 3]);
                    }

                    for (int k = 0; k < m; k++)
                        cnt[k] += grid[j][k];
                }
            }
            System.out.println(ans);
        }

        sc.close();
    }
}
