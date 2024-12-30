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
        long n = Long.parseLong(st.nextToken());
        long m = Long.parseLong(st.nextToken());
        long k = Long.parseLong(st.nextToken());
        long res = 0;
        if (k > n + m - 2)
            pw.println(-1);
        else {
            if (n - 1 >= k)
                res = Math.max(res, m * (n / (k + 1)));
            if (m - 1 >= k)
                res = Math.max(res, n * (m / (k + 1)));
            if (n - 1 < k)
                // 横切n-1次,竖切k-n+1)次
                res = Math.max(res, m / (k - (n - 1) + 1));
            if (m - 1 < k)
                res = Math.max(res, n / (k - (m - 1) + 1));
            pw.println(res);
        }
        pw.close();
        f.close();
    }

}
