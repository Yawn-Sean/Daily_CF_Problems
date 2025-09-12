import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

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

    public static void solve() {
        int n = sc.nextInt();
        StringBuilder res = new StringBuilder();
        res.append('a');
        n -= 1;

        while (n > 0) {
            int anchor = res.length();
            int copyCount = Math.min(anchor - 1, n);

            if (copyCount > 0) {
                String toCopy = res.substring(0, copyCount);
                res.append(toCopy);
                n -= copyCount;
            }
            if (n > 0) {
                char lastChar = res.charAt(anchor - 1);
                res.append((char) (lastChar + 1));
                n -= 1;
            }
        }

        out.println(res.toString());
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
