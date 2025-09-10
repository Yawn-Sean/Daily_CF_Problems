import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class Main {
    static InputReader sc = new InputReader();
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

    static boolean multiCase = false;
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

    static Set<Long> vis = new HashSet<>();
    static int[] vals = new int[16];
    static long n, L;

    public static void dfs(long cur){
        for (int i = 2; i <= 15; ++ i){
            if (vals[i] == 1){
                long nxt = cur * (i+1);
                if (nxt <= L && !vis.contains(nxt)){
                    vis.add(nxt);
                    dfs(nxt);
                }
            }
        }
    }

    public static void solve(){
        n = sc.nextLong();
        L = sc.nextLong() + 1;

        for (int i = 0; i < n; ++ i){
            vals[sc.nextInt()] = 1;
        }

        vis.add(1L);
        dfs(1);

        out.println(vis.size()-1);
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
