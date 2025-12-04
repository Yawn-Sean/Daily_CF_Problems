import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            long[] sum = new long[n + 1];
            st = new StringTokenizer(br.readLine());
            for (int ez = 1; ez <= n; ez++) {
                sum[ez] = Long.parseLong(st.nextToken());
                sum[ez] += sum[ez - 1];
            }
            long res = 0;
            ArrayDeque<Integer> dq1 = new ArrayDeque<>();
            ArrayDeque<Long> dq2 = new ArrayDeque<>();
            dq1.push(n + 1);
            dq2.push(0L);
            for (int ez = n; ez >= 0; ez--) {
                while (!dq1.isEmpty() && dq1.peek() != n + 1 && sum[ez] > sum[dq1.peek()]) {
                    dq2.pop();
                    dq1.pop();
                }
                if (!dq2.isEmpty()) {
                    dq2.push(dq2.peek() + sum[ez] * (dq1.peek() - ez));
                    dq1.push(ez);
                    res += dq2.peek() - sum[ez] * (n + 1 - ez);
                }
            }
            pw.println(res);
        }
        pw.close();
    }

}
