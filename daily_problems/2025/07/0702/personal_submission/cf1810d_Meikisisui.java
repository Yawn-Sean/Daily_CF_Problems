import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            long l = 1, r = Long.MAX_VALUE;
            st = new StringTokenizer(br.readLine());
            int q = Integer.parseInt(st.nextToken());
            for (int ez = 0; ez < q; ez++) {
                st = new StringTokenizer(br.readLine());
                int op = Integer.parseInt(st.nextToken());
                if (op == 1) {
                    long a = Long.parseLong(st.nextToken());
                    long b = Long.parseLong(st.nextToken());
                    long n = Long.parseLong(st.nextToken());
                    long L = (n - 2) * (a - b) + a + 1;
                    long R = (n - 1) * (a - b) + a;
                    // n为0时范围为[1,a]
                    if (n == 1) {
                        L = 1;
                        R = a;
                    }
                    // 有交集则区间合并，否则忽略
                    if (L > r || R < l)
                        pw.print(0 + " ");
                    else {
                        l = Math.max(l, L);
                        r = Math.min(r, R);
                        pw.print(1 + " ");
                    }
                } else {
                    long a = Long.parseLong(st.nextToken());
                    long b = Long.parseLong(st.nextToken());
                    // 两端点是否在同一天到达
                    long ans1 = 1 + Math.max(0, (l - a + (a - b - 1)) / (a - b));
                    long ans2 = 1 + Math.max(0, (r - a + (a - b - 1)) / (a - b));
                    if (ans1 == ans2)
                        pw.print(ans1 + " ");
                    else
                        pw.print(-1 + " ");
                }
            }
            pw.println();
        }
        pw.close();
        br.close();
    }

}
