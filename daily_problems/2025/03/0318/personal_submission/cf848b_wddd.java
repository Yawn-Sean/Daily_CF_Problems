import java.io.*;
import java.util.*;

public class Sorting {

    FastReader is;
    PrintWriter out;
//    String INPUT = "8 10 8\n" +
//            "1 1 10\n" +
//            "1 4 13\n" +
//            "1 7 1\n" +
//            "1 8 2\n" +
//            "2 2 0\n" +
//            "2 5 14\n" +
//            "2 6 0\n" +
//            "2 6 1\n";
    String INPUT = "10 500 500\n" +
        "2 88 59\n" +
        "2 470 441\n" +
        "1 340 500\n" +
        "2 326 297\n" +
        "1 74 45\n" +
        "1 302 273\n" +
        "1 132 103\n" +
        "2 388 359\n" +
        "1 97 68\n" +
        "2 494 465";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Sorting().run();
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
        int w = is.ni();
        int h = is.ni();
        int[][] dances = new int[n][5];
        for (int i = 0; i < n; i++) {
            dances[i] = new int[] {is.ni(), is.ni(), is.ni(), i, i};
        }

        Map<Integer, List<int[]>> intersections = new HashMap<>();
        for (int i = 0; i < dances.length; i++) {
            int[] dance = dances[i];
            int diff = dance[1] - dance[2];
            if (!intersections.containsKey(diff)) {
                intersections.put(diff, new ArrayList<>());
            }
            intersections.get(diff).add(dance);
        }

        for (List<int[]> intersection : intersections.values()) {
            Collections.sort(intersection, (i1, i2) -> {
                if (i1[0] != i2[0]) {
                    return Integer.compare(i1[0], i2[0]);
                } else {
                    if (i1[0] == 1) {
                        return Integer.compare(i2[1], i1[1]);
                    } else {
                        return Integer.compare(i1[1], i2[1]);
                    }
                }
            });
        }

        for (List<int[]> intersection : intersections.values()) {
            int start = 0;
            for (int i = 0; i < intersection.size(); i++) {
                if (intersection.get(i)[0] == 2) {
                    start = i;
                    break;
                }
            }
            if (start == 0) {
                continue;
            }

            for (int[] ii : intersection) {
                ii[4] = intersection.get(start)[3];
                start++;
                if (start == intersection.size()) {
                    start = 0;
                }
            }
        }

        for (int[] dance : dances) {
            if (dances[dance[4]][0] == 1) {
                out.println(dances[dance[4]][1] + " " + h);
            } else {
                out.println(w + " " + dances[dance[4]][1]);
            }
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
