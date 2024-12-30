import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws Exception {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        long k = Long.parseLong(st.nextToken());
        long len = 1, n = 0;
        for (long ez = 1; k - len * ez * 9 >= 0; len++, ez *= 10) {
            k -= len * ez * 9;
            n += ez * 9;
        }
        // k 是序列从有 len 位数开始的第 k 项
        n += k / len;
        // k % len != 0
        if (k % len != 0) {
            n++;
            long wei = len - (k % len);
            while (wei > 0) {
                wei--;
                n /= 10;
            }
        }
        long res = n % 10;
        pw.println(res);
        pw.close();
        f.close();
    }

}
