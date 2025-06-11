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
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());
        long mod = Long.parseLong(st.nextToken());
        long[] valid = new long[10000001];
        char[] s = new char[10];
        long limit = Math.min(b, mod);
        for (int i = 0; i <= limit; i++)
            valid[(int) (i % mod)] = 1;
        limit = Math.min(a, mod);
        long res = -1;
        for (long i = 0; i <= limit; i++) {
            long x = (i * 1000000000) % mod;
            x = (mod - x) % mod;
            if (valid[(int) x] == 0) {
                res = i;
                break;
            }
        }
        if (res == -1)
            pw.print("2");
        else {
            pw.print("1 ");
            s[9] = 0;
            int n = 8;
            for (int i = 0; i < 9; i++)
                s[i] = '0';
            while (res > 0) {
                s[n--] = (char) ((res % 10) + '0');
                res /= 10;
            }
            pw.print(new String(s, 0, 9));
        }
        pw.close();
        f.close();
    }

}
