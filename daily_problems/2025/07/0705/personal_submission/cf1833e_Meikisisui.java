import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Test3 {

    private static final int mm = 200001;
    private static int[] parent = new int[mm];
    private static int[] sz = new int[mm];
    private static int[] fg = new int[mm];
    private static Set<Integer>[] g = new HashSet[mm];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        for (int ez = 0; ez < mm; ez++)
            g[ez] = new HashSet<>();
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int res = 0, cnt = 0;
            for (int ez = 1; ez <= n; ez++) {
                g[ez] = new HashSet<>();
                parent[ez] = ez;
                fg[ez] = 0;
                sz[ez] = 1;
            }
            st = new StringTokenizer(br.readLine());
            for (int ez = 1; ez <= n; ez++) {
                int x = Integer.parseInt(st.nextToken());
                g[x].add(ez);
                g[ez].add(x);
                merge(x, ez);
            }
            for (int ez = 1; ez <= n; ez++) {
                if(fg[find(ez)] == 1 || g[ez].size() == 1)
                    fg[find(ez)] = 1;
            }
            for (int ez = 1; ez <= n; ez++) {
                if (find(ez) == ez) {
                    res++;
                    cnt += fg[ez];
                }
            }
            pw.println(Math.min(res, res - cnt + 1) + " " + res);
        }
        pw.close();
        br.close();
    }

    private static int find(int x) { 
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    private static void merge(int u, int v) { 
        u = find(u);
        v = find(v);
        if (u != v) {
            parent[u] = v;
            sz[v] += sz[u];
        }
    }

}
