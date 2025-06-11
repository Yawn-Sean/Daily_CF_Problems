import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());
        Integer[] ai = new Integer[n];
        Integer[] ti = new Integer[n];
        Integer[] index = new Integer[n];
        int res = 0, total = 0;
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(f.readLine());
            ai[ez] = Integer.parseInt(st.nextToken());
            ti[ez] = Integer.parseInt(st.nextToken());
            index[ez] = ez;
        }
        Arrays.sort(index, (a, b) -> {
            return ai[b] - ai[a];
        });
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> {
            return b - a;
        });
        for (int ez : index) {
            pq.add(ti[ez]);
            total += ti[ez];
            if (!pq.isEmpty() && total > t)
                total -= pq.poll();
            res = Math.max(res, Math.min(pq.size(), ai[ez]));
        }
        pw.println(res);
        pw.println(res);
        int cnt = 0;
        Arrays.sort(index, (a, b) -> {
            return ti[a] - ti[b];
        });
        for (int ez : index) {
            if (cnt >= res)
                break;
            if (ai[ez] >= res) {
                pw.print((ez + 1) + " ");
                cnt++;
            }
        }
        pw.close();
        f.close();
    }

}
