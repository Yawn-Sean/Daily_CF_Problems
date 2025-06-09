import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] a = new int[n + 1];
        int[] dis = new int[n + 1];
        st = new StringTokenizer(br.readLine());
        for (int ez = 1; ez <= n; ez++)
            a[ez] = Integer.parseInt(st.nextToken());
        Arrays.fill(dis, Integer.MAX_VALUE);
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(1);
        dis[1] = 0;
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            if (cur + 1 <= n && dis[cur + 1] > dis[cur] + 1) {
                dis[cur + 1] = dis[cur] + 1;
                queue.offer(cur + 1);
            }
            if (cur - 1 > 0 && dis[cur - 1] > dis[cur] + 1) {
                dis[cur - 1] = dis[cur] + 1;
                queue.offer(cur - 1);
            }
            if (dis[a[cur]] > dis[cur] + 1) {
                dis[a[cur]] = dis[cur] + 1;
                queue.offer(a[cur]);
            }
        }
        for (int ez = 1; ez <= n; ez++)
            pw.print(dis[ez] + " ");
        pw.close();
        br.close();
    }

}
