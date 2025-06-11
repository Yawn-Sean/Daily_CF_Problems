import java.io.*;
import java.util.*;

public class Constructive {

    FastReader is;
    PrintWriter out;
    String INPUT = "4\n" +
            "vasya 0\n" +
            "petya 1\n" +
            "manya 3\n" +
            "dunay 3\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Constructive().run();
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
        String[] names = new String[n];
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            names[i] = is.ns();
            a[i] = is.ni();
        }
        sort(n, names, a);
    }

    private void sort(int n, String[] names, int[] a) {
        Map<String, Integer> nameToHeight = new HashMap<>();
        List<String>[] aToNames = new List[n];
        for (int i = 0; i < n; i++) {
            aToNames[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            aToNames[a[i]].add(names[i]);
            nameToHeight.put(names[i], a[i]);
        }

        int[] aa = a.clone();
        Arrays.sort(aa);
        for (int i = 0; i < n; i++) {
            if (aa[i] > i) {
                out.println(-1);
                return;
            }
        }

        List<String> order = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (!aToNames[i].isEmpty()) {
                int insert = i;
                for (String name : aToNames[i]) {
                    order.add(insert, name);
                    insert++;
                }
            }
        }

        int height = 5000;
        Map<Integer, Integer> aToHeight = new HashMap<>();
        for (String name : order) {
            if (aToHeight.containsKey(nameToHeight.get(name))) {
                out.println(name + " " + aToHeight.get(nameToHeight.get(name)));
            } else {
                out.println(name + " " + height);
                aToHeight.put(nameToHeight.get(name), height);
                height--;
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
