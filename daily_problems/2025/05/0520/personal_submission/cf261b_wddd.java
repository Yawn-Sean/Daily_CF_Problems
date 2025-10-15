import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BruteForce {

    FastReader is;
    PrintWriter out;
    String INPUT = "3\n" +
            "1 2 3\n" +
            "3\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new BruteForce().run();
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
        int p = is.ni();

        int sum = 0;
        int[] count = new int[51];
        for (int i = 0; i < n; i++) {
            count[a[i]]++;
            sum += a[i];
        }

        if (sum <= p) {
            out.println(n);
            return;
        }

        double[] fact = new double[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }

        double total = 0;
        for (int i = 1; i < count.length; i++) {
            if (count[i] > 0) {
                count[i]--;
                total += getGuests(n, p, count, i, 1, new int[51], 0, fact);
                count[i]++;
            }
        }

        for (int i = 1; i <= n; i++) {
            total /= i;
        }

        out.println(total);
    }

    private double getGuests(int n, int p, int[] count, int separation, int ind, int[] picked, int sum, double[] fact) {
        if (sum > p) {
            return 0;
        }
        if (ind >= count.length || sum + ind > p) {
            if (sum + separation <= p) {
                return 0;
            } else {
                double result = 1;
                int total = 0;
                for (int i = 1; i < picked.length; i++) {
                    if (picked[i] > 0) {
                        result *= cab(count[i], picked[i], fact);
                    }
                    total += picked[i];
                }
                result *= count[separation] + 1;
                result *= total;
                result *= fact[total];
                result *= fact[n - 1 - total];
                return result;
            }
        }

        double result = 0;

        for (int i = 0; i <= count[ind]; i++) {
            picked[ind] = i;
            result += getGuests(n, p, count, separation, ind + 1, picked, sum + i * ind, fact);
        }
        picked[ind] = 0;

        return result;
    }

    private double cab(int a, int b, double[] fact) {
        return fact[a] / fact[b] / fact[a - b];
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
