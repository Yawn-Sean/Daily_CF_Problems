import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        PriorityQueue<Long> pq = new PriorityQueue<>();
        long jack = 0, tot = 0;
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < n; ez++) {
            long now = Long.parseLong(st.nextToken());
            int index = ez / 2 + 1;
            if (index > pq.size()) {
                jack += now;
                pq.offer(now);
            } else if (!pq.isEmpty() && pq.peek() < now) {
                jack -= pq.poll();
                jack += now;
                pq.offer(now);
            }
            tot += now;
        }
        pw.println(jack + " " + (tot - jack));
        pw.close();
    }

}
