import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        long[] cnt = new long[n + 1];
        fenwick oldSpeed = new fenwick(n + 1);
        fenwick repaired = new fenwick(n + 1);
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(f.readLine());
            int key = Integer.parseInt(st.nextToken());
            if (key == 1) {
                int di = Integer.parseInt(st.nextToken());
                int ai = Integer.parseInt(st.nextToken());
                oldSpeed.update(di, Math.max(Math.min(ai, b - cnt[di]), 0));
                repaired.update(di, Math.max(Math.min(ai, a - cnt[di]), 0));
                cnt[di] += ai;
            } else {
                int pi = Integer.parseInt(st.nextToken());
                long res = oldSpeed.sum(pi - 1) + repaired.sum(n) - repaired.sum(pi + k - 1);
                pw.println(res);
            }
        }
        pw.close();
        f.close();
    }

    private static class fenwick {
        long[] tree;
        int len;

        public fenwick(int n) {
            tree = new long[n];
            len = n;
        }

        private void update(int i, long l) {
            while (i < len) {
                tree[i] += l;
                i += (i & -i);
            }
        }

        private long sum(int i) {
            long sum = 0;
            while (i > 0) {
                sum += tree[i];
                i -= (i & -i);
            }
            return sum;
        }
    }

}
