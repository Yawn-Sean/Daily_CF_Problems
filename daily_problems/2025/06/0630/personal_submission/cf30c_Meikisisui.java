import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        Node[] a = new Node[n + 1];
        for (int ez = 1; ez <= n; ez++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            long t = Long.parseLong(st.nextToken());
            double p = Double.parseDouble(st.nextToken());
            a[ez] = new Node(x, y, t, p);
        }
        Arrays.sort(a, 1, (int) n + 1, Comparator.comparingLong(node -> node.t));
        long[][] dis = new long[n + 1][n + 1];
        double[] dp = new double[n + 1];
        for (int ez = 1; ez <= n; ez++) {
            for (int vn = ez + 1; vn <= n; vn++)
                dis[ez][vn] = dis[vn][ez] = dist(a[ez], a[vn]);
        }
        for (int ez = 1; ez <= n; ez++) {
            dp[ez] = a[ez].val;
            for (int vn = 1; vn < ez; vn++) {
                if (dis[ez][vn] > ((a[ez].t - a[vn].t) * (a[ez].t - a[vn].t)))
                    continue;
                dp[ez] = Math.max(dp[ez], dp[vn] + a[ez].val);
            }
        }
        double res = 0;
        for (int ez = 1; ez <= n; ez++)
            res = Math.max(res, dp[ez]);
        pw.printf("%.10f\n", res);
        pw.close();
        br.close();
    }

    private static class Node {
        int x, y;
        long t;
        double val;

        public Node(int x, int y, long t, double val) {
            this.x = x;
            this.y = y;
            this.t = t;
            this.val = val;
        }
    }

    private static long dist(Node aa, Node bb) {
        return (aa.x - bb.x) * (aa.x - bb.x) + (aa.y - bb.y) * (aa.y - bb.y);
    }

}
