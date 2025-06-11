import java.io.*;
import java.util.*;

public class Greedy {

    FastReader is;
    PrintWriter out;
    String INPUT = "11\n" +
            "3 9 9 6 4 3 6 4 9 6 0";

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
        int[] a = is.na(n);

        List<Integer>[] mods = new List[3];
        for (int i = 0; i < 3; i++) {
            mods[i] = new ArrayList<>();
        }
        int sum = 0;
        for (int aa : a) {
            mods[aa % 3].add(aa);
            sum += aa;
        }
        for (int i = 0; i < 3; i++) {
            Collections.sort(mods[i]);
        }

        if (mods[0].isEmpty() || mods[0].get(0) != 0) {
            out.println(-1);
        } else {
            if (sum % 3 == 1) {
                if (mods[1].isEmpty() && mods[2].size() < 2) {
                    out.println(-1);
                    return;
                }

                if (!mods[1].isEmpty()) {
                    mods[1].removeFirst();
                } else {
                    mods[2].removeFirst();
                    mods[2].removeFirst();
                }
            } else if (sum % 3 == 2) {
                if (!mods[2].isEmpty()) {
                    mods[2].removeFirst();
                } else {
                    mods[1].removeFirst();
                    mods[1].removeFirst();
                }
            }

            if (mods[1].isEmpty() && mods[2].isEmpty() && mods[0].getLast() == 0) {
                out.println(0);
                return;
            }

            StringBuilder sb = new StringBuilder();
            Queue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(i -> -mods[i[0]].get(i[1])));
            pq.add(new int[] {0, mods[0].size() - 1});
            if (!mods[1].isEmpty()) {
                pq.add(new int[] {1, mods[1].size() - 1});
            }
            if (!mods[2].isEmpty()) {
                pq.add(new int[] {2, mods[2].size() - 1});
            }
            while (!pq.isEmpty()) {
                int[] curr = pq.poll();
                sb.append(mods[curr[0]].get(curr[1]));
                curr[1]--;
                if (curr[1] >= 0) {
                    pq.add(curr);
                }
            }
            out.println(sb.toString());
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

        int[] na(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = ni();
            }
            return a;
        }
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
