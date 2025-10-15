import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    private static long a, b, xx, yy;
    private static long[] X = new long[101];
    private static long[] Y = new long[101];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        a = Long.parseLong(st.nextToken());
        b = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        String s = st.nextToken();
        if (a == 0 && b == 0) {
            pw.println("Yes");
            pw.close();
            br.close();
            return;
        }
        int len = s.length();
        long x = 0, y = 0;
        for (int ez = 0; ez < len; ez++) {
            switch (s.charAt(ez)) {
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
            }
            X[ez] = x;
            Y[ez] = y;
        }
        xx = X[len - 1];
        yy = Y[len - 1];
        for (int ez = 0; ez < len; ez++) {
            if (check(X[ez], Y[ez])) {
                pw.println("Yes");
                pw.close();
                br.close();
                return;
            }
        }
        pw.println("No");
        pw.close();
        br.close();
    }

    private static boolean check(long x, long y) {
        // 没想到该怎么二分这个判定
        long tmpX = a - x;
        long tmpY = b - y;
        if (xx == 0) {
            if (yy == 0)
                return tmpX == 0 && tmpY == 0;
            else {
                if (tmpY % yy == 0)
                    return tmpY / yy >= 0 && tmpX == 0;
            }
        } else {
            if (yy == 0) {
                if (tmpX % xx == 0)
                    return tmpX / xx >= 0 && tmpY == 0;
            } else {
                if (tmpX % xx == 0 && tmpY % yy == 0)
                    return tmpX / xx >= 0 && tmpY / yy >= 0 && tmpX / xx == tmpY / yy;
            }
        }
        return false;
    }

}
