import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main1 {

    FastReader is;
    PrintWriter out;
    String INPUT = "10 6 3\n" +
            "861947514 34945 190135645 68731 44833 387988147 84308862 878151920 458358978 809653252";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Main1().run();
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
        int k = is.ni();
        int p = is.ni();
        List<Integer> odd = new ArrayList<>();
        List<Integer> even = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int a = is.ni();
            if (a % 2 == 0) {
                even.add(a);
            } else {
                odd.add(a);
            }
        }
        if (odd.size() < k - p || (odd.size() - (k - p)) % 2 != 0 || Math.abs((odd.size() - (k - p)) / 2) + even.size() < p) {
            out.println("NO");
        } else {
            out.println("YES");
            int count = 0;
            for (int i = 0 ; i < k - p; i++, count++) {
                if (count < k - 1) {
                    out.println("1 " + odd.get(i));
                } else {
                    out.print((odd.size() - i + even.size()) + " ");
                    for (int j = i; j < odd.size(); j++) {
                        out.print(odd.get(j) + " ");
                    }
                    for (int j = 0; j < even.size(); j++) {
                        out.print(even.get(j) + " ");
                    }
                    out.println();
                    return;
                }
            }
            for (int i = k - p ; i < odd.size(); i += 2, count++) {
                if (count < k - 1) {
                    out.println("2 " + odd.get(i) + " " + odd.get(i + 1));
                } else {
                    out.print((odd.size() - i + even.size()) + " ");
                    for (int j = i; j < odd.size(); j++) {
                        out.print(odd.get(j) + " ");
                    }
                    for (int j = 0; j < even.size(); j++) {
                        out.print(even.get(j) + " ");
                    }
                    out.println();
                    return;
                }
            }
            for (int i = 0; count < k; i++, count++) {
                if (count < k - 1) {
                    out.println("1 " + even.get(i));
                } else {
                    out.print((even.size() - i) + " ");
                    while (i < even.size()) {
                        out.print(even.get(i) + " ");
                        i++;
                    }
                    out.println();
                }
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
