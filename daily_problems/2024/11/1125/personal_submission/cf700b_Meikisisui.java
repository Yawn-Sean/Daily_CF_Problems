import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    private static boolean[] dis;
    private static long res;
    private static int k;
    private static List<Integer>[] graph;
    private static int[] stat;
    private static int[] below;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        graph = new List[n];
        stat = new int[n];
        Arrays.setAll(graph, e -> new ArrayList<>());
        st = new StringTokenizer(f.readLine());
        for (int i = 0; i < 2 * k; i++) {
            int town = Integer.parseInt(st.nextToken()) - 1;
            stat[town]++;
        }
        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(f.readLine());
            int from = Integer.parseInt(st.nextToken()) - 1;
            int to = Integer.parseInt(st.nextToken()) - 1;
            graph[from].add(to);
            graph[to].add(from);
        }
        below = new int[n];
        dis = new boolean[n];
        dfs(0);
        pw.println(res);
        pw.close();
        f.close();
    }

    private static void dfs(int node) {
        dis[node] = true;
        below[node] = stat[node];
        for (Integer next : graph[node]) {
            if (dis[next])
                continue;
            dfs(next);
            below[node] += below[next];
            res += Math.min(below[next], 2 * k - below[next]);
        }
    }

}
