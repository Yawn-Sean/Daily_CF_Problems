import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    private static int n, tmp;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        n = Integer.parseInt(st.nextToken());
        int res = n - 1;
        for (int ez = 1; ez < n; ez++) {
            tmp = 0;
            dfs(n, ez);
            res = Math.min(res, tmp);
        }
        pw.println(res);
        pw.close();
        f.close();
    }

    private static void dfs(int a, int b) {
        // 辗转相除
        if (0 == b) {
            tmp = Integer.MAX_VALUE;
            return;
        } else if (1 == b) {
            tmp += a - 1;
            return;
        }
        tmp += a / b;
        dfs(b, a % b);
    }

}
