import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Hashing1 {

    FastReader is;
    PrintWriter out;
    String INPUT = "7\n" +
            "1 ab\n" +
            "5 bacaba\n" +
            "1 abacaba\n" +
            "2 aca\n" +
            "5 ba\n" +
            "2 ba\n" +
            "aba\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Hashing1().run();
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

    public static int base = 31;
    public static long[] hashes = new long[(int) (3 * 1e5 + 100)];

    void solve() {
        int n = is.ni();
        List<Vertex>[] adjs = new List[n];
        for (int i = 0; i < n; i++) {
            adjs[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            int parent = is.ni() - 1;
            String s = is.ns();
            adjs[parent].add(new Vertex(i + 1, s));
        }
        String t = is.ns();

        long powLen = 1;
        long target = 0;
        for (char c : t.toCharArray()) {
            target = target * base + c;
            powLen *= base;
        }

        long result = search(adjs, 0, 1, powLen, target, t.length());
        out.print(result);
    }

    private long search(List<Vertex>[] adjs, int curr, int currInd, long powLen, long target, int targetLen) {
        long match = 0;
        for (Vertex next : adjs[curr]) {
            int ind = currInd;
            for (char c : next.s.toCharArray()) {
                hashes[ind] = hashes[ind - 1] * base + c;
                if (ind >= targetLen) {
                    if (target == hashes[ind] - hashes[ind - targetLen] * powLen) {
                        match++;
                    }
                }
                ind++;
            }
            match += search(adjs, next.target, ind, powLen, target, targetLen);
        }

        return match;
    }

    class Vertex {
        int target;
        String s;

        public Vertex(int target, String s) {
            this.target = target;
            this.s = s;
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
