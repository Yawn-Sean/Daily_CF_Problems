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
        long k = Long.parseLong(st.nextToken());
        if (n > k * (k - 1)) {
            pw.println("NO");
            pw.close();
            f.close();
        }
        pw.println("YES");
        for (int ez = 1; ez < k; ez++) {
            if (n > 0) {
                int tmp = ez;
                for (int vn = 1; vn <= k; vn++) {
                    if (n > 0) {
                        pw.println(vn + " " + (tmp % k + 1));
                        tmp++;
                        n--;
                    } else {
                        pw.close();
                        f.close();
                    }
                }
            } else {
                pw.close();
                f.close();
            }
        }
        pw.close();
        f.close();
    }

}
