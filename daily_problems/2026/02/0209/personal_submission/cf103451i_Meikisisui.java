import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    private static int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        String a = st.nextToken();
        st = new StringTokenizer(br.readLine());
        String b = st.nextToken();
        st = new StringTokenizer(br.readLine());
        String c = st.nextToken();
        int len = a.length();
        long p2 = pow(2, n - 1);
        long res = 1;
        for (int i = 0; i < len; i++) {
            int ai = a.charAt(i) - '0';
            int bi = b.charAt(i) - '0';
            int ci = c.charAt(i) - '0';
            long tmp = 0;
            if (ai == 1 && bi == 0) {
                pw.println(0);
                pw.close();
                return;
            }
            if (ai == 1 && bi == 1) {
                if ((n & 1) == ci)
                    tmp = 1;
                else {
                    pw.println(0);
                    pw.close();
                    return;
                }
            } else if (ai == 0 && bi == 0) {
                if (ci == 0)
                    tmp = 1;
                else {
                    pw.println(0);
                    pw.close();
                    return;
                }
            } else {
                if (ci == 0) {
                    tmp = p2 - 1;
                    if ((n & 1) == 0)
                        tmp = (tmp - 1) % MOD;
                } else {
                    tmp = p2;
                    if ((n & 1) == 1)
                        tmp = (tmp - 1) % MOD;
                }
                tmp = (tmp % MOD + MOD) % MOD;
            }
            res = res * tmp % MOD;
        }
        pw.println(res);
        pw.close();
    }

    private static long pow(long a, long b) {
        long r = 1;
        a %= MOD;
        while (b > 0) {
            if ((b & 1) == 1)
                r = r * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return r;
    }

}
