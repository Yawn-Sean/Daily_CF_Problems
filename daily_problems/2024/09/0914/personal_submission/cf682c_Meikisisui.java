import javafx.util.Pair;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    private static int n;
    private static List<Pair<Integer, Long>>[] v;
    private static int[] a;
    private static int[] vis;
    private static long res;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        n = Integer.parseInt(st.nextToken());
        a = new int[n + 1];
        vis = new int[n + 1];
        v = new ArrayList[n + 1];
        Arrays.setAll(v, e -> new ArrayList<>());
        st = new StringTokenizer(f.readLine());
        for (int i = 1; i <= n; i++)
            a[i] = Integer.parseInt(st.nextToken());
        for (int i = 2; i <= n; i++) {
            st = new StringTokenizer(f.readLine());
            int p = Integer.parseInt(st.nextToken());
            long c = Long.parseLong(st.nextToken());
            v[i].add(new Pair<>(p, c));
            v[p].add(new Pair<>(i, c));
        }

        res = 0;
        dfs(1, 0);
        pw.println(n - res);
        pw.close();
        f.close();
    }

    private static void dfs(int x, long sum) {
        vis[x] = 1;
        if (sum <= a[x])
            res++;
        else
            return;
        for (Pair<Integer, Long> pair : v[x]) {
            int i = pair.getKey();
            long y = pair.getValue();
            if (vis[i] == 0)
                dfs(i, Math.max(0, sum + y));
        }
    }

}
