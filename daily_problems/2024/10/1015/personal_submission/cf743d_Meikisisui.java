import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Test2 {

    private static long dp[][], a[];
    private static List<Integer>[] graph;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        graph = new List[n];
        Arrays.setAll(graph, k -> new ArrayList<>());
        a = new long[n];
        dp = new long[n][3];
        st = new StringTokenizer(f.readLine());
        for (int ez = 0; ez < n; ez++)
            a[ez] = Long.parseLong(st.nextToken());
        for (int ez = 0; ez < n - 1; ez++) {
            st = new StringTokenizer(f.readLine());
            int from = Integer.parseInt(st.nextToken()) - 1;
            int to = Integer.parseInt(st.nextToken()) - 1;
            graph[from].add(to);
            graph[to].add(from);
        }
        dfs(0, -1);
        long res = Long.MIN_VALUE;
        for (int ez = 0; ez < n; ez++)
            res = Math.max(res, dp[ez][2]);
        pw.println(res == Long.MIN_VALUE ? "Impossible" : res);
        pw.close();
        f.close();
    }

    static void dfs(int now, int from) {
        dp[now][0] = a[now];
        long max1 = Long.MIN_VALUE, max2 = Long.MIN_VALUE;
        for (int x : graph[now]) {
            if (x == from)
                continue;
            dfs(x, now);
            dp[now][0] += dp[x][0];
            if (dp[x][1] > max1) {
                max2 = max1;
                max1 = dp[x][1];
            } else if (dp[x][1] > max2)
                max2 = dp[x][1];
        }
        dp[now][1] = Math.max(dp[now][0], max1);
        if (max2 != Long.MIN_VALUE)
            dp[now][2] = max1 + max2;
        else
            dp[now][2] = Long.MIN_VALUE;
    }

}
