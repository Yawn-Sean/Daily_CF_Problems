import java.io.*;
import java.util.*;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n + 1];
        boolean[] visited1 = new boolean[n + 1], visited2 = new boolean[n + 1];
        List<Integer>[] graph1 = new List[n + 1], graph2 = new List[n + 1];
        for (int ez = 1; ez <= n; ez++)
            arr[ez] = Integer.parseInt(st.nextToken());
        Arrays.setAll(graph1, ez -> graph1[ez] = new ArrayList<>());
        Arrays.setAll(graph2, ez -> graph2[ez] = new ArrayList<>());
        for (int ez = 0; ez < m; ez++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            graph1[from].add(to);
            graph2[to].add(from);
        }
        Queue<Integer> queue = new LinkedList<>();
        for (int ez = 1; ez <= n; ez++) {
            if (arr[ez] == 1) {
                queue.add(ez);
                visited1[ez] = true;
            }
        }
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            for (int ez = 0; ez < graph1[cur].size(); ez++) {
                int next = graph1[cur].get(ez);
                if (visited1[next]) continue;
                if (arr[next] == 1) continue;
                visited1[next] = true;
                queue.add(next);
            }
        }
        // 再跑一遍，这次从2开始反向跑
        queue = new LinkedList<>();
        for (int ez = 1; ez <= n; ez++) {
            if (arr[ez] == 2) {
                queue.add(ez);
                visited2[ez] = true;
            }
        }
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            for (int ez = 0; ez < graph2[cur].size(); ez++) {
                int next = graph2[cur].get(ez);
                if (arr[next] == 1)
                    visited2[next] = true;
                if (visited2[next]) continue;
                visited2[next] = true;
                queue.add(next);
            }
        }
        // 两次跑完都被标记的就是答案
        for (int ez = 1; ez <= n; ez++) {
            if (visited1[ez] && visited2[ez])
                pw.println("1");
            else
                pw.println("0");
        }
        pw.close();
    }


}
