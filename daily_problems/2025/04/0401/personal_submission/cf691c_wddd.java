import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class String1 {

    FastReader is;
    PrintWriter out;
    String INPUT = "0.0012";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new String1().run();
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
        String num = is.ns();

        int dot = -1;
        for (int i = 0; i < num.length(); i++) {
            if (num.charAt(i) == '.') {
                dot = i;
                break;
            }
        }

        int leading = 0;
        for (int i = 0; i < num.length(); i++) {
            if (num.charAt(i) == '0' || num.charAt(i) == '.') {
                leading++;
            } else {
                break;
            }
        }

        StringBuilder sb = new StringBuilder();
        int len = dot == -1 ? num.length() - leading - 1 : dot - leading - (dot > leading ? 1 : 0);
        if (dot <= leading) {
            sb.append(num, leading, num.length());
        } else {
            sb.append(num, leading, dot);
            sb.append(num, dot + 1, num.length());
        }
        if (sb.length() > 1) {
            sb.insert(1, '.');
        }
        for (int i = sb.length() - 1; i >= 1; i--) {
            if (sb.charAt(i) == '0' || sb.charAt(i) == '.') {
                sb.setLength(i);
            } else {
                break;
            }
        }
        if (len != 0) {
            sb.append("E");
            sb.append(len);
        }
        out.println(sb.toString());
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
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
