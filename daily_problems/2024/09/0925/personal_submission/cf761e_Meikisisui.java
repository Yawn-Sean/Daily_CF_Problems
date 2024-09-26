import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    static class Node {
        int x, y;

        Node(int _x, int _y) {
            x = _x;
            y = _y;
        }
    }

    private static List<Integer>[] graph = new List[31];
    private static boolean[] vis = new boolean[31];
    private static int[] dx = {1, 0, -1, 0};
    private static int[] dy = {0, -1, 0, 1};
    private static Node[] res = new Node[31];

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        Arrays.setAll(graph, e -> new ArrayList<>());
        for (int ez = 0; ez < n - 1; ez++) {
            st = new StringTokenizer(f.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            graph[from].add(to);
            graph[to].add(from);
        }
        for (int ez = 1; ez <= n; ez++) {
            if (graph[ez].size() > 4) {
                pw.println("NO");
                pw.close();
                f.close();
            }
        }
        pw.println("YES");
        res[1] = new Node(0, 0);
        // 保证30个点都在一条线上也排的下
        dfs(1, 0, 0, -1, 28);
        for (int ez = 1; ez <= n; ez++)
            pw.println(res[ez].x + " " + res[ez].y);
        pw.close();
        f.close();
    }

    private static void dfs(int from, int x, int y, int dir, int num) {
        if (vis[from])
            return;
        vis[from] = true;
        int nextdir = 0;
        for (int ez = 0; ez < graph[from].size(); ez++) {
            int to = graph[from].get(ez);
            if (vis[to])
                continue;
            if (nextdir == dir)
                nextdir = (nextdir + 1) % 4;
            int nextx = x + dx[nextdir] * (1 << num);
            int nexty = y + dy[nextdir] * (1 << num);
            res[to] = new Node(nextx, nexty);
            dfs(to, nextx, nexty, (nextdir + 2) % 4, num - 1);
            nextdir = (nextdir + 1) % 4;
        }
    }

}
