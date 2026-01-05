import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    private static int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int d = Integer.parseInt(st.nextToken());
            long p = quickPow(2, d, MOD);
            long term1 = ((d - 3L) % MOD + MOD) % MOD * p % MOD;
            long term2 = (d + 3L) % MOD;
            long sum = (term1 + term2) % MOD;
            long ans = (2L * p % MOD) * sum % MOD;
            pw.println(ans);
        }
        pw.close();
    }

    // 新快速幂板子
    public static long quickPow(int a, int b, int p) {
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
