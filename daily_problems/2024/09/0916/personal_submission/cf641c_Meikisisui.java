import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        int a = 0, b = 1;
        while (q-- > 0) {
            st = new StringTokenizer(f.readLine());
            int type = Integer.parseInt(st.nextToken());
            if (type == 2) {
                a ^= 1;
                b ^= 1;
            } else {
                int x = Integer.parseInt(st.nextToken());
                a = ((a + x) % n + n) % n;
                b = ((b + x) % n + n) % n;
            }
        }
        int[] res = new int[n];
        for (int ez = a, j = b, vn = 1; vn <= n / 2; vn++) {
            res[ez] = 2 * vn - 1;
            res[j] = 2 * vn;
            ez = (ez + 2) % n;
            j = (j + 2) % n;
        }
        for (int ez = 0; ez < n; ez++) {
            if (ez == n - 1)
                pw.println(res[ez]);
            else
                pw.print(res[ez] + " ");
        }
        pw.close();
        f.close();
    }

}
