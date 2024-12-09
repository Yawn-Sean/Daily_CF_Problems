import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        long a = Long.parseLong(st.nextToken());
        st = new StringTokenizer(f.readLine());
        String s = st.nextToken();
        int maxn = 40001;
        long res = 0;
        int len = s.length();
        int[] sum = new int[len + 1];
        int[] map = new int[maxn];

        for (int ez = 1; ez <= len; ez++)
            sum[ez] = s.charAt(ez - 1) - '0';
        for (int ez = 1; ez <= len; ez++)
            sum[ez] += sum[ez - 1];
        for (int ez = 1; ez <= len; ez++) {
            for (int vn = 1; vn <= ez; vn++)
                map[sum[ez] - sum[vn - 1]]++;
        }
        if (a == 0) {
            for (int ez = 1; ez < maxn; ++ez)
                res += (long) map[0] * map[ez];
            res *= 2;
            res += (long) map[0] * map[0];
        } else {
            for (int ez = 1; ez < maxn; ez++) {
                if (a % (long) ez == 0) {
                    if ((a / ez) >= maxn)
                        continue;
                    res += (long) map[ez] * map[(int) (a / ez)];
                }
            }
        }
        pw.println(res);
        pw.close();
        f.close();
    }

}
