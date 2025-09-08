import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.Stack;
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

    static int n, m, p;
    static int[] p1, p2, st;
    public static int find(int[] ps, int x){
        int y = x;
        while (ps[y] != y){
            y = ps[y];
        }
        while (ps[x] != x){
            int j = x;
            x = ps[x];
            ps[j] = y;
        }
        return y;
    }
    public static void merge1(int x, int y){
        x = find(p1, x);
        y = find(p1, y);
        if (x < y){
            p1[y] = x;
        } else {
            p1[x] = y;
        }
    }
    public static void merge2(int x, int y){
        x = find(p2, x);
        y = find(p2, y);
        if (x > y){
            p2[y] = x;
        } else {
            p2[x] = y;
        }
    }
    public static void mergeBoth(int x, int y){
        merge1(x, y);
        merge2(x, y);
    }
    public static int moveL(int pos){
        if (st[pos] == 1) return find(p1, pos) - 1;
        else return pos;
    }
    public static int moveR(int pos){
        if (st[pos] == 1) return find(p2, pos) + 1;
        else return pos;
    }
    public static void merge(int l, int r){
        int j = l;
        while (j < r){
            st[j] = 1;
            mergeBoth(j, j+1);
            j = find(p2, j);
        }
        st[j] = 1;

        if (l-1 >= 0 && st[l-1] == 1) mergeBoth(l-1, l);
        if (r+1 < n && st[r+1] == 1) mergeBoth(r, r+1);
    }
    public static int move(int pos){
        int j = moveR(pos);
        if (j < n) return j;
        return moveL(pos);
    }

    public static void solve(){
        n = sc.nextInt();
        m = sc.nextInt();
        p = sc.nextInt()-1;
        p1 = new int[n];
        p2 = new int[n];
        for (int i = 0; i < n; ++ i){
            p1[i] = p2[i] = i;
        }
        st = new int[n];
        int[] pairs = new int[n];
        StringBuilder bk = new StringBuilder(sc.next());
        StringBuilder ops = new StringBuilder(sc.next());
        Stack<Integer> stk = new Stack<>();

        for (int i = 0; i < n; ++ i){
            if (bk.charAt(i) == '('){
                stk.add(i);
            } else {
                int j = stk.pop();
                pairs[j] = i;
                pairs[i] = j;
            }
        }

        for (int i = 0; i < m; ++ i){
            char op = ops.charAt(i);
            if (op == 'L'){
                p = moveL(p-1);
            } else if (op == 'R'){
                p = moveR(p+1);
            } else {
                int oth = pairs[p];
                if (oth < p){
                    merge(oth, p);
                } else {
                    merge(p, oth);
                }
                p = move(p);
            }
        }

        for (int i = 0; i < n; ++ i){
            if (st[i] == 0) out.print(bk.charAt(i));
        }
        out.println();
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
