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
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        pw.println(Math.min(n - 1, k));
        List<int[]>[] graph = new List[n + 1];
        boolean[] visited = new boolean[n + 1];
        int cnt = -1;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            return a[1] - b[1];
        });
        Arrays.setAll(graph, e -> new ArrayList<>());
        for (int ez = 1; ez <= m; ez++) {
            st = new StringTokenizer(f.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            graph[x].add(new int[]{y, w, ez});
            graph[y].add(new int[]{x, w, ez});
        }
        pq.add(new int[]{1, 0, -1});
        while (pq.size() > 0) {
            int[] p = pq.poll();
            int now = p[0];
            int dis = p[1];
            int index = p[2];
            if (visited[now])
                continue;
            visited[now] = true;
            cnt++;
            if (index != -1)
                pw.print(index + " ");
            // 根据题意，如果已经有k条最短边就结束
            if (cnt >= k)
                break;
            for (int[] neigh : graph[now]) {
                int next = neigh[0];
                int nextDis = neigh[1];
                int nextIndex = neigh[2];
                if (!visited[next])
                    pq.add(new int[]{next, dis + nextDis, nextIndex});
            }
        }
        pw.close();
        f.close();
    }

}
