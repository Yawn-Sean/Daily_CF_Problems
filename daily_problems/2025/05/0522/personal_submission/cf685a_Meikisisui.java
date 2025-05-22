import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    private static long xx, yy;
    private static int[] visited = new int[7];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        if (n * m > 6543210) {
            pw.println(0);
            pw.close();
            br.close();
            return;
        }
        long nn = n, mm = m;
        n--;
        m--;
        while (n > 0) {
            xx++;
            n /= 7;
        }
        while (m > 0) {
            yy++;
            m /= 7;
        }
        xx = Math.max(xx, 1);
        yy = Math.max(yy, 1);
        long res = 0;
        for (long ez = 0; ez < nn; ez++) {
            for (long vn = 0; vn < mm; vn++) {
                if (check(ez, vn))
                    res++;
            }
        }
        pw.println(res);
        pw.close();
        br.close();
    }

    private static boolean check(long x, long y) {
        long a = x, b = y;
        for (int ez = 0; ez <= 6; ez++)
            visited[ez] = 0;
        for (int ez = 1; ez <= xx; ez++) {
            visited[(int) (a % 7)]++;
            a /= 7;
        }
        for (int ez = 1; ez <= yy; ez++) {
            visited[(int) (b % 7)]++;
            b /= 7;
        }
        for (int ez = 0; ez <= 6; ez++) {
            if (visited[ez] >= 2)
                return false;
        }
        return true;
    }

}
