import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Test3 {

    static List<Integer>[] graph;
    static int[] visited;
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        graph = new ArrayList[n + 1];
        visited = new int[n + 1];
        for (int ez = 1; ez <= n; ez++)
            graph[ez] = new ArrayList<>();
        for (int ez = 1; ez <= n - 1; ez++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            graph[x].add(y);
            graph[y].add(x);
        }
        visited[1] = 1;
        dfs(1, 0);
        int maxV = visited[1];
        for (int ez = 1; ez <= n; ez++)
            maxV = Math.max(maxV, visited[ez]);
        pw.println(maxV);
        for (int ez = 1; ez <= n; ez++)
            pw.print(visited[ez] + " ");
        pw.close();
        br.close();
    }

    private static void dfs(int now, int pre) {
        int cnt = 1;
        for (int neighbor : graph[now]) {
            if (neighbor == pre)
                continue;
            while (cnt == visited[now] || cnt == visited[pre])
                cnt++;
            visited[neighbor] = cnt++;
        }
        for (int neighbor : graph[now]) {
            if (neighbor != pre)
                dfs(neighbor, now);
        }
    }

}
