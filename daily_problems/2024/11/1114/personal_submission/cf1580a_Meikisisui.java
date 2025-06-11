import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int t = Integer.parseInt(st.nextToken());
        for (int ez = 0; ez < t; ez++) {
            st = new StringTokenizer(f.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int[][] a = new int[n + 1][m + 1];
            int[][] s = new int[n + 1][m + 1];
            int[] pre = new int[m + 1];
            for (int vn = 1; vn <= n; vn++) {
                st = new StringTokenizer(f.readLine());
                String str = st.nextToken();
                for (int ks = 1; ks <= m; ks++) {
                    a[vn][ks] = str.charAt(ks - 1) - '0';
                    s[vn][ks] = s[vn - 1][ks] + a[vn][ks];
                }
            }
            int res = Integer.MAX_VALUE;
            for (int i = 1; i <= n; i++) {
                for (int j = i + 4; j <= n; j++) {
                    int sum = 0;
                    pre[0] = Integer.MAX_VALUE;
                    for (int k = 1; k <= m; k++) {
                        int p1 = s[j - 1][k] - s[i][k];
                        int p0 = 2 - a[i][k] - a[j][k];
                        int cnt = j - i - 1 - p1;
                        if (k > 3)
                            res = Math.min(res, pre[k - 3] + sum + cnt);
                        sum += p1 + p0;
                        pre[k] = Math.min(pre[k - 1], cnt - sum);
                    }
                }
            }
            pw.println(res);
        }
        pw.close();
        f.close();
    }

}
