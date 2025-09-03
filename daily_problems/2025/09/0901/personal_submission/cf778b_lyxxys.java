import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class Main {

    static InputReader sc = new InputReader();
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

    static boolean multiCase = false;
    static boolean fileInputOutput = false;
    static final double eps = 1e-12;
    static final long long_inf = (long) 4e18;
    static final int int_inf = (int) 2e9;

    static <T extends Comparable<T>> T max(T u, T v) {
        return u.compareTo(v) >= 0 ? u : v;
    }

    static <T extends Comparable<T>> T min(T u, T v) {
        return u.compareTo(v) <= 0 ? u : v;
    }
    public static void error() {
        out.println(-1);
    }

    static int n, m;
    static List<int[]> lists = new ArrayList<>();
    static List<int[]> args = new ArrayList<>(); // [operand, "and(0), or(1), xor(2)", operand] || []

    static int[] ans1, ans2;

    public static void ansOutput(int[] ans){
        for (int i = 0; i < ans.length; ++ i){
            out.print(ans[i]);
        }
        out.println();
    }
    public static boolean isQue(String str){
        return str.charAt(0) == '?';
    }
    public static int compute(int x, int opera, int y, int digit, int bool){
        x = x == -1 ? bool : lists.get(x)[digit];
        y = y == -1 ? bool : lists.get(y)[digit];

        if (opera == 0) return x & y;
        else if (opera == 1) return x | y;
        else return x ^ y;
    }
    public static int forceCount(int digit, int bool){
        int res = 0;
        for (int i = 0; i < n; ++ i){
            if (args.get(i).length == 0){
                res += lists.get(i)[digit];
                continue;
            }

            lists.get(i)[digit] = compute(args.get(i)[0], args.get(i)[1], args.get(i)[2], digit, bool);
            res += lists.get(i)[digit];
        }
        return res;
    }

    public static void solve() {
        n = sc.nextInt();
        m = sc.nextInt();
        ans1 = new int[m];
        ans2 = new int[m];

        Map<String, Integer> mapTo = new HashMap<>();

        for (int i = 0; i < n; ++ i){
            String line = sc.nextLine();
            String[] splits = line.split(" ");
            lists.add(new int[m]);

            if (splits.length == 3){
                args.add(new int[0]);
                for (int j = 0; j < m; ++ j){
                    lists.get(i)[j] = Integer.parseInt(String.valueOf(splits[2].charAt(j)));
                }
            } else {
                args.add(new int[3]);
                args.get(i)[0] = isQue(splits[2]) ? -1 : mapTo.get(splits[2]);
                args.get(i)[1] = splits[3].equals("AND") ? 0 : (splits[3].equals("OR") ? 1 : 2);
                args.get(i)[2] = isQue(splits[4]) ? -1 : mapTo.get(splits[4]);
            }

            mapTo.put(splits[0], i);
        }


        for (int i = 0; i < m; ++ i){
            int c1 = forceCount(i, 1), c2 = forceCount(i, 0);
            if (c1 < c2) ans1[i] = 1;
            if (c1 > c2) ans2[i] = 1;
        }

        ansOutput(ans1);
        ansOutput(ans2);

    }

    public static void main(String[] args) throws IOException {
        int T_case = 1;
        if (multiCase) T_case = sc.nextInt();
        while (T_case > 0) {
            solve();
            T_case -= 1;
        }
        out.close();
    }


    static class InputReader {
        private StringTokenizer st;
        private BufferedReader bf;  // 字符缓冲流

        public InputReader() {
            bf = new BufferedReader(new InputStreamReader(System.in));
            st = null;
        }

        public String next() {
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

        public void setStream(InputStream stream) {
            bf = new BufferedReader(new InputStreamReader(stream, StandardCharsets.UTF_8));
        }

        public void clear() {
            st = null;
        }
    }
}
