import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class BruteForce {

    FastReader is;
    PrintWriter out;
    String INPUT = "bbaabaabbb\n";

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
        String s = is.ns();

        List<Integer>[] inds = new List[26];
        for (int i = 0; i < inds.length; i++) {
            inds[i] = new ArrayList<>();
        }
        for (int i = 0; i < s.length(); i++) {
            inds[s.charAt(i) - 'a'].add(i);
        }

        int wins = 0;
        for (int i = 0; i < 26; i++) {
            if (inds[i].isEmpty()) {
                continue;
            }
            int maxWins = 0;
            for (int j = 1; j < s.length(); j++) {
                int[] target = new int[26];
                for (int ind : inds[i]) {
                    target[s.charAt((ind + j) % s.length()) - 'a']++;
                }
                int tempWins = 0;
                for (int t : target) {
                    if (t == 1) {
                        tempWins++;
                    }
                }
                maxWins = Math.max(maxWins, tempWins);
            }
            wins += maxWins;
        }
        out.println((double) wins / s.length());
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
