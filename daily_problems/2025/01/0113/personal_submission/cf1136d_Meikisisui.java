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
        int m = Integer.parseInt(st.nextToken());
        int[] parent = new int[n + 1];
        int[] cnt = new int[n + 1];
        List<Integer>[] graph = new List[n + 1];
        Arrays.setAll(graph, e -> new ArrayList<>());
        st = new StringTokenizer(f.readLine());
        for (int ez = 1; ez <= n; ez++)
            parent[ez] = Integer.parseInt(st.nextToken());
        for (int ez = 1; ez <= m; ez++) {
            st = new StringTokenizer(f.readLine());
            int front = Integer.parseInt(st.nextToken());
            int behind = Integer.parseInt(st.nextToken());
            graph[behind].add(front);
        }
        int res = 0;
        for (int ez = n; ez >= 1; ez--) {
            // 从后往前扫，ez==n时，先把边加到cnt里
            // 如果有n-ez个人和他交换，那么他可以和最后一个换
            if (cnt[parent[ez]] == n - ez - res && ez != n)
                res++;
            else {
                for (int next : graph[parent[ez]])
                    cnt[next]++;
            }
        }
        pw.println(res);
        pw.close();
        f.close();
    }

}
