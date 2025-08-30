import java.io.*;
import java.util.*;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        PriorityQueue<Node> pq = new PriorityQueue();
        for (int ez = 0; ez < k; ez++)
            pq.offer(new Node(0, 0L, 0L));
        List<Node> list = new ArrayList();
        long[] res = new long[n];
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(br.readLine());
            long s = Long.parseLong(st.nextToken());
            long m = Long.parseLong(st.nextToken());
            list.add(new Node(ez, s, m));
        }
        Collections.sort(list);
        for (int ez = 0; ez < n; ez++) {
            int index = list.get(ez).id;
            long x = list.get(ez).a, y = list.get(ez).b;
            Node now = pq.poll();
            x = Math.max(x, now.a);
            x += y;
            res[index] = x;
            pq.add(new Node(index, x, 0L));
        }
        for (int ez = 0; ez < n; ez++)
            pw.println(res[ez]);
        pw.close();
    }

    private static class Node implements Comparable<Node> {
        private int id;
        private long a, b;

        private Node(int id, long a, long b) {
            this.id = id;
            this.a = a;
            this.b = b;
        }

        public int compareTo(Node o) {
            return Long.compare(a, o.a);
        }
    }


}
