import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    private static List<Integer>[] graph;  // 邻接矩阵可能会爆内存
    private static int[] du;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        graph = new List[n + 1];  // 节点从1
        du = new int[n + 1];
        Arrays.setAll(graph, e -> new ArrayList<>());
        for (int ez = 0; ez < m; ez++) {
            st = new StringTokenizer(f.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            graph[from].add(to);
            graph[to].add(from);
            du[from]++;
            du[to]++;
        }
        if (m >= n * (n - 1) / 2) {
            pw.println("NO");
            pw.close();
            f.close();
            return;
        }
        int tag1 = 1, tag2 = 2;
        for (int ez = 1; ez <= n; ez++) {
            if (du[ez] != n - 1) {
                tag1 = ez;
                break;
            }
        }
        for (int ez = 1; ez <= n; ez++) {
            // 如果时间爆就优化这里
            if (ez != tag1 && !graph[ez].contains(tag1)) {
                tag2 = ez;
                break;
            }
        }
        pw.println("YES");
        int cnt = 0;
        for (int ez = 1; ez <= n; ez++) {
            if (ez == tag1)
                pw.print(n + " ");
            else if (ez == tag2)
                pw.print((n - 1) + " ");
            else
                pw.print(++cnt + " ");
        }
        pw.println();
        cnt = 0;
        for (int ez = 1; ez <= n; ez++) {
            // 没关系的两个节点都给n
            if (ez == tag1 || ez == tag2)
                pw.print(n + " ");
            else
                pw.print(++cnt + " ");
        }
        pw.println();
        pw.close();
        f.close();
    }

}
