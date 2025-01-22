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
        int k = Integer.parseInt(st.nextToken());
        ArrayList<Integer>[] graph = new ArrayList[n];
        int[] degree = new int[n];
        Arrays.setAll(graph, e -> new ArrayList<>());
        for (int ez = 1; ez < n; ez++) {
            st = new StringTokenizer(f.readLine());
            int from = Integer.parseInt(st.nextToken()) - 1;
            int to = Integer.parseInt(st.nextToken()) - 1;
            graph[from].add(to);
            graph[to].add(from);
            degree[from]++;
            degree[to]++;
        }
        LinkedList<Integer> queue = new LinkedList<>();
        for (int ez = 0; ez < n; ez++) {
            if (degree[ez] == 1)
                queue.add(ez);
        }
        while (queue.size() > 1 && k > 0) {
            int len = queue.size();
            Set<Integer> set = new HashSet<>();
            int cnt = 0;
            int[] pick = new int[n];
            while (len-- > 0) {
                int now = queue.poll();
                degree[now]--;
                for (int next : graph[now]) {
                    if (degree[next] > 0) {
                        pick[next]++;
                        if (pick[next] == 1)
                            cnt++;
                        if (pick[next] == 3)
                            cnt--;
                        degree[next]--;
                        set.add(next);
                    }
                    if (degree[next] == 1)
                        queue.add(next);
                }
            }
            if (cnt > 0 || set.size() != queue.size()) {
                pw.print("No");
                pw.flush();
                return;
            }
            k--;
        }
        if (queue.size() == 1 && k == 0)
            pw.print("Yes");
        else
            pw.print("No");
        pw.close();
        f.close();
    }

}
