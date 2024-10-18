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
        st = new StringTokenizer(f.readLine());
        int[] p = new int[n + 1];
        int[] pre = new int[n + 1];
        pre[0] = 0;
        for (int ez = 1; ez <= n; ez++)
            pre[ez] = pre[ez - 1] ^ ez;
        for (int ez = 1; ez <= n; ez++)
            p[ez] = Integer.parseInt(st.nextToken());
        int res = p[1];
        for (int ez = 2; ez <= n; ez++)
            res ^= p[ez];
        for (int ez = 1; ez <= n; ez++) {
            int tmp = n / ez;
            if ((tmp & 1) == 1)
                res ^= pre[ez - 1];
            if (n % ez != 0)
                res ^= pre[n % ez];
        }
        pw.println(res);
        pw.close();
        f.close();
    }

}
