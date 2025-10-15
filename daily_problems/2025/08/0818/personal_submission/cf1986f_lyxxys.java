import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static InputReader sc = new InputReader();
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

    static boolean multiCase = true;
    static boolean fileInputOutput = false;
    static final double eps = 1e-12;
    static final long long_inf = (long)4e18;
    static final int int_inf = (int)2e9;

    static <T extends Comparable<T>> T max(T u, T v){
        return u.compareTo(v) >= 0 ? u : v;
    }
    private static <T extends Comparable<T>> T min(T u, T v){
        return u.compareTo(v) <= 0 ? u : v;
    }
    static <T> void print(T[] A) {
        int n = A.length;
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                out.print(" ");
            }
            out.print(A[i]);
        }
        out.println();
    }

    static int n, m, snap;
    static List<List<int[]>> g = new ArrayList<>();
    static int[] dfn, low, sz;
    static long ans;

    public static void tarjan(int u, int rev){
        dfn[u] = low[u] = ++ snap;

        for (int i = 0; i < g.get(u).size(); ++ i){
            int[] edge = g.get(u).get(i);
            int v = edge[0], nxt_rev = edge[1];

            if (dfn[v] == 0){
                tarjan(v, nxt_rev);
                low[u] = min(low[u], low[v]);
                sz[u] += sz[v];
                if (low[v] > dfn[u]){
                    ans = max(ans, 1L * sz[v] * (n - sz[v]));
                }
            } else if (i != rev){
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

    public static void solve(){
        n = sc.nextInt();
        m = sc.nextInt();
        g.clear();
        dfn = new int[n];
        low = new int[n];
        sz = new int[n];
        ans = 0;
        snap = 0;

        for (int i = 0; i < n; ++ i){
            g.add(new ArrayList<>());
            sz[i] = 1;
        }

        for (int i = 0; i < m; ++ i){
            int u = sc.nextInt()-1, v = sc.nextInt()-1;
            int ru = g.get(u).size(), rv = g.get(v).size();
            g.get(u).add(new int[]{v, rv});
            g.get(v).add(new int[]{u, ru});
        }

        tarjan(0, -1);

        out.println(1L*n*(n-1)/2 - ans);
    }

    public static void main(String[] args) throws IOException {
        if (fileInputOutput){
            out = new PrintWriter(new OutputStreamWriter(new FileOutputStream("files/out.txt"), StandardCharsets.UTF_8));
            sc.setStream(new FileInputStream("files/in.txt"));
        }
        int T_case = 1;
        if (multiCase) T_case = sc.nextInt();
        while (T_case > 0){
            solve();
            T_case -= 1;
        }
        out.close();
    }
    static class InputReader {
        private StringTokenizer st;
        private BufferedReader bf;  // 字符缓冲流

        public InputReader(){
            bf = new BufferedReader(new InputStreamReader(System.in));
            st = null;
        }

        public String next(){
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(bf.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        public String nextLine() {
            try {
                return bf.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public void setStream(InputStream stream){
            bf = new BufferedReader(new InputStreamReader(stream, StandardCharsets.UTF_8));
        }
    }
}
