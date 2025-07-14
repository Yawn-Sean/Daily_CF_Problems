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
    static <T extends Comparable<T>> T min(T u, T v){
        return u.compareTo(v) <= 0 ? u : v;
    }
    public static void error(){
        out.println(-1);
    }

    public static void solve2(int n, int m){
        boolean is_rotate = false;

        if (n > m) {
            int o = n;
            n = m;
            m = o;
            is_rotate = true;
        }

        if ((n == 1 && m == 3) || (n == 1 && m == 2) || (n == 2 && m == 2)) {
            error();
            return;
        }

        int[][] ans = new int[n][m];
        for (int i = 0; i < n; ++ i){
            Arrays.fill(ans[i], -1);
        }

        int mov = 0;
        if (n == 1){
            for (int i = 1; i < m; i += 2){
                ans[0][mov++] = i;
            }
            for (int i = 0; i < m; i += 2){
                ans[0][mov++] = i;
            }
        } else {
            for (int i = 0; i < n; ++ i){
                for (int j = 0; j < m; ++ j){
                    int x = i, y = j;
                    while (ans[x][y] == -1){
                        ans[x][y] = mov++;
                        x = (x+1) % n;
                        y = (y+1) % m;
                    }
                }
            }
        }
        if (mov != n*m){
            throw new RuntimeException("mov 错误");
        }

        if (is_rotate){
            for (int j = 0; j < m; ++ j){
                for (int i = 0; i < n; ++ i){
                    if (i > 0) out.print(" ");
                    out.print(ans[i][j]+1);
                }
                out.print("\n");
            }
        } else {
            for (int i = 0; i < n; ++ i){
                for (int j = 0; j < m; ++ j){
                    if (j > 0) out.print(" ");
                    out.print(ans[i][j]+1);
                }
                out.print("\n");
            }
        }
    }
    public static void solve(){
        int n = sc.nextInt(), m = sc.nextInt();
        solve2(n, m);
    }

    public static void main(String[] args) throws IOException{
        int T_case = 1;
        if (multiCase) T_case = sc.nextInt();
        while (T_case > 0){
            solve();
            T_case -= 1;
        }
        out.close( );
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
        public void clear(){
            st = null;
        }
    }
}
