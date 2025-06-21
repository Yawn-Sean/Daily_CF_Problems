import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        Node[] nodes = new Node[n + 1];

        for (int ez = 1; ez <= n; ++ez) {
            st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());
            nodes[ez] = new Node(x, y, ez);
        }
        Arrays.sort(nodes, 1, n + 1, (a, b) -> {
            if (a.x == b.x)
                return Long.compare(a.y, b.y);
            return Long.compare(a.x, b.x);
        });

        for (int ez = 3; ez <= n; ++ez) {
            if (isNotLine(nodes[1], nodes[2], nodes[ez])) {
                pw.printf(nodes[1].id + " " + nodes[2].id + " " + nodes[ez].id);
                pw.close();
                br.close();
                return;
            }
        }
        pw.close();
        br.close();
    }

    private static class Node {
        long x, y;
        int id;

        Node(long x, long y, int id) {
            this.x = x;
            this.y = y;
            this.id = id;
        }
    }

    private static boolean isNotLine(Node nodes, Node b, Node c) {
        return (b.y - nodes.y) * (c.x - b.x) != (c.y - b.y) * (b.x - nodes.x);
    }

}
