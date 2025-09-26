import java.io.*;
import java.util.Arrays;
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
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());
            long[] a = new long[n];
            st = new StringTokenizer(br.readLine());
            for (int ez = 0; ez < n; ez++)
                a[ez] = Long.parseLong(st.nextToken());
            long[] pre = new long[n + 1];
            long[] back = new long[n + 1];
            Arrays.fill(pre, Long.MAX_VALUE);
            Arrays.fill(back, Long.MAX_VALUE);
            for (int ez = 0; ez < n; ez++)
                pre[ez + 1] = Math.min(pre[ez], a[ez] - (a[ez] & y));
            for (int ez = n - 1; ez >= 0; ez--)
                back[ez] = Math.min(back[ez + 1], a[ez] - (a[ez] & y));
            long total = 0;
            for (long num : a)
                total += num;
            long res = Long.MAX_VALUE;
            for (int ez = 0; ez < n; ez++) {
                long tmp = total - a[ez] + (a[ez] | x);
                long delta = Math.min(pre[ez], back[ez + 1]);
                delta = Math.min(delta, (a[ez] | x) - ((a[ez] | x) & y));
                tmp -= delta;
                res = Math.min(res, tmp);
            }
            pw.println(res);
        }
        pw.close();
    }

}
