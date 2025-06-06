import java.io.*;
import java.util.*;

public class Greedy {

    FastReader is;
    PrintWriter out;
    String INPUT = "3\n" +
            "kokoko tlin\n" +
            "koko kotlin\n" +
            "ko kokotlin";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Greedy().run();
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
        int n = is.ni();

        String[] sHashes = new String[n];
        int[] tHashes = new int[n];
        for (int i = 0; i < n; i++) {
            String s = is.ns();
            String t = is.ns();

            int tHash = hash(t);
            for (int j = s.length() - 1; j >= -1; j--) {
                if (j == -1) {
                    sHashes[i] = "";
                    break;
                }
                if ((tHash & (1 << (s.charAt(j) - 'a'))) == 0) {
                    sHashes[i] = s.substring(0, j + 1);
                    break;
                }
            }

            tHashes[i] = tHash;
        }

        int total = 0;
        Map<Integer, Map<String, List<Integer>>> hashToCount = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (!hashToCount.containsKey(tHashes[i])) {
                hashToCount.put(tHashes[i], new HashMap<>());
            }
            if (!hashToCount.get(tHashes[i]).containsKey(sHashes[i])) {
                hashToCount.get(tHashes[i]).put(sHashes[i], new ArrayList<>());
                total++;
            }
            hashToCount.get(tHashes[i]).get(sHashes[i]).add(i);
        }

        out.println(total);
        for (Map<String, List<Integer>> sLists : hashToCount.values()) {
            for (List<Integer> l : sLists.values()) {
                out.print(l.size() + " ");
                for (int ind : l) {
                    out.print((ind + 1) + " ");
                }
                out.println();
            }
        }
    }

    private int hash(String s) {
        int h = 0;
        for (char c : s.toCharArray()) {
            h |= 1 << (c - 'a');
        }
        return h;
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
