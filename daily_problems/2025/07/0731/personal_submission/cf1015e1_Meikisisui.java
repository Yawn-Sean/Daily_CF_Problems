import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    private static int m, n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        char[][] grid = new char[n][m];
        boolean[][] visited = new boolean[n][m];
        int[] x = new int[n * m], y = new int[n * m], res = new int[n * m];
        int cnt = 0, ans = 0;
        for (int ez = 0; ez < n; ez++) 
            grid[ez] = br.readLine().toCharArray();

        for (int ez = 1; ez < n; ez++) {
            for (int vn = 1; vn < m; vn++) {
                if (grid[ez][vn] == '*') {
                    int flag = 0;
                    for (int r = 1; check(ez, vn, r); r++) {
                        // 暴力的去找当前中心最大的半径，不知道怎么优化复杂度了
                        if (grid[ez - r][vn] == '*' && grid[ez][vn - r] == '*' && grid[ez + r][vn] == '*' && grid[ez][vn + r] == '*') {
                            flag = r;
                            visited[ez][vn] = true;
                            visited[ez - r][vn] = true;
                            visited[ez][vn - r] = true;
                            visited[ez + r][vn] = true;
                            visited[ez][vn + r] = true;
                        } else
                            break;
                    }
                    if (flag > 0) {
                        x[cnt] = ez;
                        y[cnt] = vn;
                        res[cnt++] = flag;
                        ans += flag;
                    }
                }
            }
        }
        boolean isNotOk = false;
        for (int ez = 0; ez < n; ez++) {
            for (int vn = 0; vn < m; vn++) {
                if (grid[ez][vn] == '*' && !visited[ez][vn]) {
                    isNotOk = true;
                    break;
                }
            }
        }
        if (isNotOk)
            pw.println("-1");
        else {
            pw.println(ans);
            for (int ez = 0; ez < ans; ez++) {
                for (int vn = 1; vn <= res[ez]; vn++)
                    pw.println((x[ez] + 1) + " " + (y[ez] + 1) + " " + vn);
            }
        }
        pw.close();
    }

    private static boolean check(int i, int j, int k) {
        if (i - k < 0 || i + k >= n || j - k < 0 || j + k >= m)
            return false;
        return true;
    }

}
