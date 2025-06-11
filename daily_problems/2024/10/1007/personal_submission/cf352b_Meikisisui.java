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
        List<Long> res = new ArrayList<>();
        for (int k = 0; k <= 64 - Long.numberOfLeadingZeros(n - 1) + 1; k++) {
            // 原来可以这么写二分
            long a = 0;
            long b = 2000000002;
            for (long m = (a + b) / 2; a + 1 < b; m = (a + b) / 2) {
                if ((2L << k) - 3L + m <= 2L * n / m)
                    a = m;
                else
                    b = m;
            }
            if (a % 2L == 0L)
                continue;
            if (a * ((1L << k) - 1L) + a * (a - 1L) / 2L == n)
                res.add(a * (1L << k));
        }

        if (res.size() == 0) {
            pw.println(-1);
            pw.close();
            f.close();
        }
        Collections.sort(res);
        for (long r : res)
            pw.println(r);
        pw.close();
        f.close();
    }


}
