import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        pw.println("YES");
        if (k % 2 == 0) {
            for (int ez = 0; ez < n; ez++)
                pw.print(".");
            pw.println();
            for (int vn = 0; vn < 2; vn++) {
                int lie = k / 2;
                pw.print(".");
                int ez = 1;
                for (; lie > 0; lie--, ez++)
                    pw.print("#");
                for (; ez < n; ez++)
                    pw.print(".");
                pw.println();
            }
            for (int ez = 0; ez < n; ez++)
                pw.print(".");
        } else {
            for (int ez = 0; ez < n; ez++)
                pw.print(".");
            pw.println();

            int two = 0, three = 0, threeMid = 0, vn = 0;
            if (k <= n - 2)
                two = (n - k) / 2;
            else {
                two = 1;
                three = k - n + 2;
            }
            for (; vn < two; vn++)
                pw.print(".");
            for (vn = 0; vn < n - two * 2; vn++)
                pw.print("#");
            for (vn = 0; vn < two; vn++)
                pw.print(".");
            pw.println();

            vn = 0;
            for (; vn < (n - three) / 2; vn++)
                pw.print(".");
            for (vn = 0; vn < three / 2; vn++)
                pw.print("#");
            pw.print(".");
            for (vn = 0; vn < three / 2; vn++)
                pw.print("#");
            for (vn = 0; vn < (n - three) / 2; vn++)
                pw.print(".");
            pw.println();

            for (int ez = 0; ez < n; ez++)
                pw.print(".");
        }
        pw.close();
        f.close();
    }

}
