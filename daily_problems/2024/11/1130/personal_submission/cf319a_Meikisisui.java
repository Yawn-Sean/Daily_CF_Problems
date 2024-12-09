import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    private static int MOD = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        String x = st.nextToken();
        int n = x.length();
        int[] pre = new int[2 * n + 1];
        pre[0] = 1;
        for (int ez = 1; ez <= 2 * n; ez++)
            pre[ez] = 2 * pre[ez - 1] % MOD;
        int res = 0;
        for (int ez = 0; ez < n; ez++) {
            if (x.charAt(ez) == '1')
                res = (res + pre[2 * n - ez - 2]) % MOD;
        }
        pw.println(res);
        pw.close();
        f.close();
    }

}
