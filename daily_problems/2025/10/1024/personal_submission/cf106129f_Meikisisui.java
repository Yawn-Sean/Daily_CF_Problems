import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        char[][] grid = new char[n][m];
        for (int ez = 0; ez < n; ez++)
            grid[ez] = br.readLine().toCharArray();
        int total = 0;
        for (int ez = 0; ez < n; ez++) {
            for (int vn = 0; vn < m; vn++) {
                if (grid[ez][vn] == '#')
                    total++;
            }
        }
        for (int a = Math.min(n, m); a > 0; a--) {
            if (total % (a * a) == 0) {
                int[][] tmp = new int[n][m];
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        if (grid[x][y] == '#')
                            tmp[x][y] = 1;
                    }
                }
                boolean isOk = true;
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        if (tmp[x][y] == 1) {
                            for (int dx = x; dx < x + a; dx++) {
                                for (int dy = y; dy < y + a; dy++) {
                                    if (dx >= n || dy >= m || tmp[dx][dy] != 1) {
                                        isOk = false;
                                        break;
                                    }
                                    tmp[dx][dy] = 0;
                                }
                                if (!isOk) break;
                            }
                            if (!isOk) break;
                        }
                    }
                    if (!isOk) break;
                }
                if (isOk) {
                    pw.println(a);
                    pw.close();
                    return;
                }
            }
        }
        pw.close();
    }

}
