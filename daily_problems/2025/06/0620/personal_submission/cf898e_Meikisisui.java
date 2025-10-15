import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        PriorityQueue<Integer> q1 = new PriorityQueue<>();
        PriorityQueue<Integer> q2 = new PriorityQueue<>();
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < n; ez++) {
            int x = Integer.parseInt(st.nextToken());
            int cnt = (int) Math.sqrt(x);
            if (cnt * cnt == x) {
                if (cnt == 0)
                    q1.offer(2);
                else
                    q1.offer(1);
            } else {
                int cost = Math.min((cnt + 1) * (cnt + 1) - x, x - cnt * cnt);
                q2.offer(cost);
            }
        }
        long res = 0;
        while (q1.size() > n / 2)
            res += q1.poll();
        while (q2.size() > n / 2)
            res += q2.poll();
        pw.println(res);
        pw.close();
        br.close();
    }

}
