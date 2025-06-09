import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Greedy {

    FastReader is;
    PrintWriter out;
    String INPUT = "16 999\n" +
            "9595959.95959595";

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
        int t = is.ni();
        char[] score = is.ns(n);

        int decimal = -1;
        for (int i = 0; i < n; i++) {
            if (score[i] == '.') {
                decimal = i;
            } else if (decimal > 0 && score[i] >= '5') {
                int ind = i - 1;
                while (ind >= 0) {
                    if (t == 0) {
                        ind++;
                        break;
                    } else {
                        if (score[ind] != '.') {
                            score[ind]++;
                            if (score[ind] < '5') {
                                break;
                            } else if (score[ind] <= '9') {
                                if (ind < decimal) {
                                    break;
                                }
                                t--;
                            }
                        }
                    }

                    ind--;
                }
                
                print(score, decimal - 1, ind);
                return;
            }
        }

        print(score, decimal - 1, score.length - 1);
    }

    private void print(char[] score, int decimal, int cut) {
        for (int i = 0; i <= Math.max(decimal, cut); i++) {
            if (score[i] == ('9' + 1)) {
                out.print(i == 0 ? "10" : "0");
            } else {
                out.print(score[i]);
            }
        }
        out.println();
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
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
