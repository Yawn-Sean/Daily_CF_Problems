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
        int n = Integer.parseInt(st.nextToken());
        int[] a = new int[n + 1];
        boolean[] vis = new boolean[n + 1];
        st = new StringTokenizer(br.readLine());
        for (int ez = 1; ez <= n; ez++)
            a[ez] = Integer.parseInt(st.nextToken());
        boolean flag = false;
        long res = 1;
        for (int ez = 1; ez <= n; ez++) {
            if (vis[ez])
                continue;
            int next = a[ez];
            vis[ez] = true;
            int cnt = 1;
            // 找环
            while (next != ez) {
                next = a[next];
                vis[next] = true;
                cnt++;
                if (cnt > n) {
                    // 非环
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
            if (cnt % 2 == 0)
                cnt /= 2;
            res = res * cnt / gcd(cnt, res);
        }
        if (flag)
            pw.println("-1");
        else
            pw.println(res);
        pw.close();
        br.close();
    }

    private static long gcd(long a, long b) {
        while (b != 0) {
            long c = b;
            b = a % b;
            a = c;
        }
        return a;
    }

}
