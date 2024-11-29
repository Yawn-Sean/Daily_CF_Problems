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
        long res = 0;
        for (int ez = 0; ez < m; ez++) {
            st = new StringTokenizer(f.readLine());
            res += n * Long.parseLong(st.nextToken());
            long di = Long.parseLong(st.nextToken());
            if (di < 0) {
                if (n % 2 == 0)
                    res += n * n / 4 * di;
                else
                    res += n / 2 * (n / 2 + 1) * di;
            } else
                res += (n * (n - 1) / 2 * di);
        }
        pw.println((double) res / n);
        pw.close();
        f.close();
    }

}
