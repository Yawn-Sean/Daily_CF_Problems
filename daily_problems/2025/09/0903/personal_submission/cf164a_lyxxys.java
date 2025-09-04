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

    static int n, m;
    static int[] state, st1, st2;
    static List<List<Integer>> g1 = new ArrayList<>(), g2 = new ArrayList<>();

    public static void dfs1(int u){
        if (st1[u] > 0) return;
        st1[u] = 1;

        for (Integer v : g1.get(u)) {
            dfs1(v);
        }
    }
    public static void dfs2(int u){
        if (st2[u] > 0) return;
        st2[u] = 1;
        if (state[u] == 1) return;

        for (Integer v : g2.get(u)) {
            dfs2(v);
        }
    }

    public static void solve(){
        n = sc.nextInt();
        m = sc.nextInt();
        state = new int[n];
        st1 = new int[n];
        st2 = new int[n];

        for (int i = 0; i < n; ++ i){
            g1.add(new ArrayList<>());
            g2.add(new ArrayList<>());
            state[i] = sc.nextInt();
        }

        for (int i = 0,u,v; i < m; ++ i){
            u = sc.nextInt()-1;
            v = sc.nextInt()-1;
            g1.get(u).add(v);
            g2.get(v).add(u);
        }

        for (int i = 0; i < n; ++ i){
            if (state[i] == 1) dfs1(i);
            if (state[i] == 2) dfs2(i);
        }

        for (int i = 0; i < n; ++ i){
            out.println(st1[i] > 0 && st2[i] > 0 ? 1 : 0);
        }
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
}
