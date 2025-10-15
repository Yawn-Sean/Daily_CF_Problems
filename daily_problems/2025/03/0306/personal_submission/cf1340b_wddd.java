import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Naive3 {

    FastReader is;
    PrintWriter out;
    String INPUT = "";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Naive3().run();
    }

    void run() throws Exception {
        is = oj ? new FastReader(System.in) : new FastReader(new ByteArrayInputStream(INPUT.getBytes()));
        out = new PrintWriter(System.out);

        long s = System.currentTimeMillis();
        solve();
        out.flush();
        objTr(System.currentTimeMillis() - s + "ms");
        out.close();
    }

    static char[][] TARGET = new char[10][7];
    static {
        TARGET[0] = "1110111".toCharArray();
        TARGET[1] = "0010010".toCharArray();
        TARGET[2] = "1011101".toCharArray();
        TARGET[3] = "1011011".toCharArray();
        TARGET[4] = "0111010".toCharArray();
        TARGET[5] = "1101011".toCharArray();
        TARGET[6] = "1101111".toCharArray();
        TARGET[7] = "1010010".toCharArray();
        TARGET[8] = "1111111".toCharArray();
        TARGET[9] = "1111011".toCharArray();
    }

    void solve() {
        int n = is.ni();
        int k = is.ni();
        char[][] numbers = is.nm(n, 7);
        String[][] cache = new String[k + 1][n + 1];
        String maxNum = maxDisplay(numbers, k, 0, cache);
        out.println(maxNum == null || maxNum.equals("t") ? "-1" : maxNum);
    }

    private String maxDisplay(char[][] numbers, int k, int ind, String[][] cache) {
        if (ind >= numbers.length) {
            return k != 0 ? "t" : "";
        }

        if (cache[k][ind] != null) {
            return cache[k][ind];
        }

        char[] curr = numbers[ind];
        for (int i = 9; i >= 0; i--) {
            int diff = diff(curr, i);
            if (diff >= 0 && diff <= k) {
                String next = maxDisplay(numbers, k - diff, ind + 1, cache);
                if (!"t".equals(next)) {
                    cache[k][ind] = i + next;
                    return i + next;
                }
            }
        }
        cache[k][ind] = "t";
        return "t";
    }

    private int diff(char[] curr, int target) {
        int diff = 0;
        for (int i = 0; i < 7; i++) {
            if (curr[i] == '1' && TARGET[target][i] == '0') {
                return -1;
            }
            if (curr[i] == '0' && TARGET[target][i] == '1') {
                diff++;
            }
        }
        return diff;
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        String ns() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        int ni() {
            return Integer.parseInt(ns());
        }

        private boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }

        char[] ns(int n) {
            try {
                char[] buf = new char[n];
                for (int i = 0; i < n; i++) {
                    char c = (char) br.read();
                    while (isSpaceChar(c)) {
                        c = (char) br.read();
                    }
                    buf[i] = c;
                }
                return buf;
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        private char[][] nm(int n, int m) {
            char[][] map = new char[n][];
            for (int i = 0; i < n; i++) {
                map[i] = ns(m);
            }
            return map;
        }
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
