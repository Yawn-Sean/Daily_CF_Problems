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
        int k = Integer.parseInt(st.nextToken());
        String[] s = new String[n];
        int[][] dp = new int[n][n];  // 换成a的次数
        boolean[][] visited = new boolean[n][n];  // 下一步i,j是否可走
        int aCnt = 0;  // 开头a走的最长路径
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(f.readLine());
            s[ez] = st.nextToken();
        }

        visited[0][0] = true;
        for (int ez = 0; ez < n; ez++) {
            for (int vn = 0; vn < n; vn++) {
                if (ez == 0 && vn == 0)
                    dp[ez][vn] = 0;
                else if (ez == 0)
                    dp[ez][vn] = dp[ez][vn - 1];
                else if (vn == 0)
                    dp[ez][vn] = dp[ez - 1][vn];
                else
                    dp[ez][vn] = Math.min(dp[ez - 1][vn], dp[ez][vn - 1]);
                dp[ez][vn] += s[ez].charAt(vn) == 'a' ? 0 : 1;
                if (dp[ez][vn] <= k) {
                    aCnt = Math.max(aCnt, ez + vn + 1);
                    // 更新下一步可以走的目标格子
                    if (ez < n - 1)
                        visited[ez + 1][vn] = true;
                    if (vn < n - 1)
                        visited[ez][vn + 1] = true;
                }
            }
        }

        String res = "";
        for (int ez = 0; ez < aCnt; ez++)
            res += 'a';
        for (int ez = aCnt; ez < 2 * n - 1; ez++) {
            // 每一步走的可能格子是vn, ez-vn,且visited为true的格子
            // 每一步走完要更新下一步可能走的格子vn+1,ez-vn和vn,ez-vn+1并控制越界
            char minChar = 'z';
            for (int vn = 0; vn < n; vn++) {
                if (ez - vn >= 0 && ez - vn < n && visited[vn][ez - vn])
                    minChar = (char) Math.min(minChar, s[vn].charAt(ez - vn));
            }
            for (int vn = 0; vn < n; vn++) {
                if (ez - vn >= 0 && ez - vn < n && visited[vn][ez - vn] && minChar == s[vn].charAt(ez - vn)) {
                    if (vn < n - 1)
                        visited[vn + 1][ez - vn] = true;
                    if (ez - vn < n - 1)
                        visited[vn][ez - vn + 1] = true;
                }
            }
            res += minChar;
        }
        pw.println(res);
        pw.close();
        f.close();
    }

}
