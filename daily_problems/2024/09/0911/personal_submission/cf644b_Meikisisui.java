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
        int b = Integer.parseInt(st.nextToken());
        Deque<long[]> dq = new ArrayDeque<>();
        long next = 0;
        while (n-- > 0) {
            st = new StringTokenizer(f.readLine());
            long t = Long.parseLong(st.nextToken());
            if (next == 0)
                next = t;
            long d = Long.parseLong(st.nextToken());
            while (!dq.isEmpty() && dq.peekFirst()[1] <= t)
                dq.pollFirst();
            if (dq.size() > b)
                pw.print("-1 ");
            else {
                // 这题还能wa了想啥呢艹
                next = Math.max(next, t) + d;
//                next += d;
                dq.offerLast(new long[]{t, next});
                // 入队时打印结束时间
                pw.print(next + " ");
            }
        }
        pw.close();
        f.close();
    }

}
