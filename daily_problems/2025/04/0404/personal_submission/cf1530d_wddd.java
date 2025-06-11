import java.io.*;
import java.util.*;

public class Random1 {

    FastReader is;
    PrintWriter out;
    String INPUT = "3\n" +
            "3\n" +
            "2 1 2\n" +
            "7\n" +
            "6 4 6 2 4 5 6\n" +
            "6\n" +
            "5 3 4 3 4 2\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Random1().run();
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

    static Random RANDOM = new Random();

    void solve() {
        int t = is.ni();
        while (t > 0) {
            t--;

            int n = is.ni();
            int[] a = is.na(n);

            gift(n, a);
        }
    }

    private void gift(int n, int[] a) {
        Map<Integer, List<Integer>> sources = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int target = a[i] - 1;
            if (!sources.containsKey(target)) {
                sources.put(target, new ArrayList<>());
            }
            sources.get(target).add(i);
        }

        Set<Integer> remaining = new HashSet<>();
        for (int i = 0; i < n; i++) {
            if (!sources.containsKey(i)) {
                remaining.add(i);
            }
        }

        loop1: while (true) {
            int[] b = new int[n];
            Arrays.fill(b, -1);

            loop2: for (Map.Entry<Integer, List<Integer>> entry : sources.entrySet()) {
                int size = entry.getValue().size();

                if (size == 1) {
                    if (b[entry.getValue().get(0)] == -1) {
                        b[entry.getValue().get(0)] = entry.getKey();
                    } else {
                        continue loop1;
                    }
                } else {
                    int start = RANDOM.nextInt(size);
                    for (int i = 0; i < size; i++) {
                        int ind = (i + start) % size;
                        if (b[entry.getValue().get(ind)] == -1) {
                            b[entry.getValue().get(ind)] = entry.getKey();
                            continue loop2;
                        }
                    }
                    continue loop1;
                }
            }

            loop3: for (int t = 0; t < 10; t++) {
                int[] bb = b.clone();
                List<Integer> shuffled = new ArrayList<>(remaining);
                Collections.shuffle(shuffled);
                int p = 0;
                for (int i = 0; i < n; i++) {
                    if (bb[i] == -1) {
                        bb[i] = shuffled.get(p);
                        if (bb[i] == i) {
                            continue loop3;
                        }
                        p++;
                    }
                }

                out.println(sources.size());
                for (int i = 0; i < n; i++) {
                    out.print(bb[i] + 1);
                    out.print(" ");
                }
                out.println();
                return;
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
