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
        long x1 = Integer.parseInt(st.nextToken());
        long y1 = Integer.parseInt(st.nextToken());
        long x2 = Integer.parseInt(st.nextToken());
        long y2 = Integer.parseInt(st.nextToken());
        Node[] node = new Node[n + 1];
        for (int ez = 1; ez <= n; ez++) {
            st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());
            node[ez] = new Node(dis(x, y, x1, y1), dis(x, y, x2, y2));
        }
        node[0] = new Node(0, 0);
        Arrays.sort(node, 1, n + 1, Comparator.comparingLong(a -> a.x));
        long sum = Long.MAX_VALUE;
        for (int ez = 0; ez <= n; ez++) {
            long tmp = 0;
            for (int vn = ez + 1; vn <= n; vn++)
                tmp = Math.max(tmp, node[vn].y);
            sum = Math.min(sum, tmp + node[ez].x);
        }
        pw.println(sum);
        pw.close();
        br.close();
    }

    private static class Node {
        long x, y;

        Node(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    private static long dis(long x0, long y0, long x, long y) {
        return (x - x0) * (x - x0) + (y - y0) * (y - y0);
    }

}
