import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        if (a == 1 || b == 1) {
            pw.print("1");
            for (int ez = 2; ez <= n; ez++)
                pw.print(" " + ez);
            pw.close();
            br.close();
            return;
        }
        int x = 0, y = 0;
        for (int ez = 0; ez <= n / a; ez++) {
            if ((n - a * ez) % b == 0) {
                x = ez;
                y = (n - a * ez) / b;
                break;
            }
        }
        if (x == 0 && y == 0) {
            pw.println("-1");
            pw.close();
            br.close();
            return;
        }
        int ans = 1;
        for (int ez = 0; ez < x; ez++) {
            for (int vn = 0; vn < a - 1; vn++)
                pw.print((ans + vn + 1) + " ");
            pw.print(ans + " ");
            ans += a;
        }
        for (int ez = 0; ez < y; ez++) {
            for (int vn = 0; vn < b - 1; vn++)
                pw.print((ans + vn + 1) + " ");
            pw.print(ans + " ");
            ans += b;
        }
        pw.close();
        br.close();
    }

}
