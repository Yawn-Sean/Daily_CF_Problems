import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    private static final int MOD = 998244353;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int T = Integer.parseInt(st.nextToken());
        while (T-- > 0) {
            st = new StringTokenizer(f.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());
            int[][] query = new int[q + 1][2];
            for (int i = 1; i <= q; i++) {
                st = new StringTokenizer(f.readLine());
                query[i][0] = Integer.parseInt(st.nextToken());
                query[i][1] = Integer.parseInt(st.nextToken());
            }

            boolean[] row = new boolean[n + 1];
            boolean[] col = new boolean[m + 1];
            int rcnt = 0;
            int ccnt = 0;
            long res = 1;
            // 从后往前找出每次染色的行和列
            for (int i = q; i > 0; i--) {
                // 该行或该列都被选择过了
                if (row[query[i][0]] && col[query[i][1]])
                    continue;
                // 着色满了
                if (rcnt == n || ccnt == m)
                    break;
                // 可以着色就是k倍的可能
                res = (res * k) % MOD;
                if (!row[query[i][0]])
                    rcnt++;
                if (!col[query[i][1]])
                    ccnt++;
                row[query[i][0]] = true;
                col[query[i][1]] = true;
            }
            pw.println(res);
        }
        pw.close();
        f.close();
    }

}
