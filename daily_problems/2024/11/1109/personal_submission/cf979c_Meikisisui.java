import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    private static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        List<Integer>[] edges = new ArrayList[n + 1];
        Arrays.setAll(edges, e -> new ArrayList<>());
        String[] ab = new String[2];
        for (int ez = 0; ez < n - 1; ez++) {
            st = new StringTokenizer(f.readLine());
            ab[0] = st.nextToken();
            ab[1] = st.nextToken();
            int from = Integer.parseInt(ab[0]);
            int to = Integer.parseInt(ab[1]);
            edges[from].add(to);
            edges[to].add(from);
        }
        dfs(edges, x, -1, y);
        int ans1 = ans;
        ans = 0;
        dfs(edges, y, -1, x);
        long res = ((long) n * (n - 1)) - ((long) ans1 * ans);
        pw.println(res);
        pw.close();
        f.close();
    }

    private static int dfs(List<Integer>[] edges, int node, int from, int find) {
        int sum = 0;
        for (int ez = 0; ez < edges[node].size(); ez++) {
            if (edges[node].get(ez) != from)
                sum += dfs(edges, edges[node].get(ez), node, find);
        }
        sum++;
        if (node == find)
            ans = sum;
        return sum;
    }

}
