import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    private static final int MOD = 1000000009;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        long n = Long.parseLong(st.nextToken());
        long m = Long.parseLong(st.nextToken());
        long k = Long.parseLong(st.nextToken());
        long cnt = n - m;
        long minX = n / k;
        long ans = 0;
        if (cnt >= minX)
            ans = m;
        else {
            long tmp = quickPow(2, minX - cnt + 1, MOD) - 2;
            tmp = (tmp + MOD) % MOD;
            tmp = tmp * k % MOD;
            ans = tmp + (m - (minX - cnt) * k);
            ans %= MOD;
        }
        pw.println(ans);
        pw.close();
        f.close();
    }

    public static long quickPow(long a, long b, int p) {
        // 防止p=1，否则返回0
        long res = 1 % p;
        while (b > 0) {
            // b最后一位是否是1
            if ((b & 1) == 1)
                res = res * a % p;
            a = (int) ((long) a * a % p);
            // 删除b最后一位
            b >>= 1;
        }
        return (int) res;
    }

}
