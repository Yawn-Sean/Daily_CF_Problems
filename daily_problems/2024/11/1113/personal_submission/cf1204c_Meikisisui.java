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
        int[][] graph = new int[n + 1][n + 1];
        for (int[] row : graph)
            Arrays.fill(row, Integer.MAX_VALUE / 3);
        for (int ez = 1; ez <= n; ez++) {
            st = new StringTokenizer(f.readLine());
            String s = st.nextToken();
            for (int vn = 1; vn <= n; vn++) {
                if (s.charAt(vn - 1) == '1')
                    graph[ez][vn] = 1;
            }
        }

        // floyd
        for (int k = 1; k <= n; k++) {
            for (int ez = 1; ez <= n; ez++) {
                for (int vn = 1; vn <= n; vn++) {
                    if (graph[ez][vn] > graph[ez][k] + graph[k][vn])
                        graph[ez][vn] = graph[ez][k] + graph[k][vn];
                }
            }
        }
        st = new StringTokenizer(f.readLine());
        int m = Integer.parseInt(st.nextToken());
        int[] p = new int[m + 1];
        int[] res = new int[m + 1];
        st = new StringTokenizer(f.readLine());
        for (int ez = 0; ez < m; ez++)
            p[ez] = Integer.parseInt(st.nextToken());

        int pre = 0, cnt = 0;
        res[cnt++] = p[0];
        for (int ez = 1; ez < m - 1; ez++) {
            // 一个点可以省略，当且仅当其前节点和后节点之间的最短路必须经过该点
            // 或者前节点和后节点为同一个点
            if (graph[p[pre]][p[ez + 1]] != graph[p[pre]][p[ez]] + graph[p[ez]][p[ez + 1]] || p[pre] == p[ez + 1]) {
                res[cnt++] = p[ez];
                pre = ez;
            }
        }
        res[cnt++] = p[m - 1];
        pw.println(cnt);
        for (int ez = 0; ez < cnt; ez++)
            pw.print(res[ez] + " ");
        pw.close();
        f.close();
    }


}
