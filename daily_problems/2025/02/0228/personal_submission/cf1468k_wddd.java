import java.io.*;
import java.util.*;

public class Naive1 {

    FastReader is;
    PrintWriter out;
    String INPUT = "4\n" +
            "L\n" +
            "RUUDL\n" +
            "LLUU\n" +
            "DDDUUUUU\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Naive1().run();
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

    void solve() {
        int t = is.ni();
        for (int i = 0; i < t; i++) {
            String s = is.ns();
            boolean found = move(s, new int[] {0, 0}, null);
            if (!found) {
                out.println("0 0");
            }
        }
    }

    private boolean move(String s, int[] p, int[] block) {
        int x = p[0];
        int y = p[1];
        for (char c : s.toCharArray()) {
            int nx = x;
            int ny = y;
            switch (c) {
                case 'L': nx--; break;
                case 'R': nx++; break;
                case 'U': ny++; break;
                case 'D': ny--; break;
            }
            if (block != null) {
                if (nx == block[0] && ny == block[1]) {
                    continue;
                } else {
                    x = nx;
                    y = ny;
                }
            } else {
                if (move(s, p, new int[] {nx, ny})) {
                    return true;
                }
                x = nx;
                y = ny;
            }
        }
        if (x == 0 && y == 0) {
            out.println(block[0] + " " + block[1]);
            return true;
        } else {
            return false;
        }
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
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
