import java.io.*;
import java.util.*;

public class Stack1 {

    FastReader is;
    PrintWriter out;
    String INPUT = "4 3\n" +
            "3 4 2";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new Stack1().run();
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
        int[] p = new int[n];
        for (int i = 0; i < k; i++) {
            p[i] = is.ni();
        }

        Deque<Integer> stack = new ArrayDeque<>();
        int ind = k;
        int min = 1;
        for (int i = 0; i < k; i++) {
            stack.add(p[i]);
            while (!stack.isEmpty() && stack.getLast() == min) {
                stack.removeLast();
                min++;
            }
        }

        while (!stack.isEmpty()) {
            int curr = stack.removeLast();
            for (int i = curr - 1; i >= min; i--) {
                if (ind >= n) {
                    out.println(-1);
                    return;
                }

                p[ind] = i;
                ind++;
            }
            min = curr + 1;
        }

        int remaining = n;
        for (int i = ind; i < n; i++) {
            p[i] = remaining;
            remaining--;
        }

        boolean[] visited = new boolean[n + 1];
        for (int i = 0; i < p.length; i++) {
            if (visited[p[i]]) {
                out.println(-1);
                return;
            }
            visited[p[i]] = true;
        }

        for (int i = 0; i < n; i++) {
            out.print(p[i]);
            out.print(" ");
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
