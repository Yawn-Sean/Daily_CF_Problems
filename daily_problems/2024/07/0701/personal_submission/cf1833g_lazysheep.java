import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class cf1833g {
    static boolean ok;
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int tt = Integer.parseInt(reader.readLine());
        while (tt-- > 0) {
            solve();
        }
        writer.close();
        reader.close();
    }

    static void solve() throws IOException {
        ok = true;
        int n = Integer.parseInt(reader.readLine());
//        System.out.println(n);
        List<int[]>[] g = new List[n + 1];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int i = 1; i < n; i++) {
            String[] tokens = reader.readLine().split(" ");
            int u = Integer.parseInt(tokens[0]), v = Integer.parseInt(tokens[1]);
            g[u].add(new int[]{v, i});
            g[v].add(new int[]{u, i});
        }
        List<Integer> ans = new ArrayList<>();
        int cnt = dfs(1, -1, g, ans);
        if (cnt == 3 && ok) {
            writer.write(ans.size() + "\n");
            for (int x : ans) {
                writer.write(x + " ");
            }
            writer.write("\n");
        } else {
            writer.write("-1\n");
        }
    }

    static int dfs(int x, int fa, List<int[]>[] g, List<Integer> ans) throws IOException {
        if (!ok)    return 0;
        int cnt = 0;
        for (int[] e : g[x]) {
            int y = e[0], id = e[1];
            if (y == fa) {
                continue;
            }
            int c = dfs(y, x, g, ans);
            if (c == 3) {
                ans.add(id);
            } else {
                cnt += c;
            }
            if (!ok)    return 0;
        }
        if (cnt >= 3) {
            ok = false;
            return 0;
        }
//        writer.write(x + " " + cnt + "\n");
        return cnt + 1;
    }
}
