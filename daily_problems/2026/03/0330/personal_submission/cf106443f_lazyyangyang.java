import java.util.Scanner;

public class Main {
    static final int MOD = 1000000007;
    static long quickPow(long a, long b, long mod) {
        long res = 1;
        a %= mod;
        while (b > 0) {
            if ((b & 1) == 1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            long total = (long) (n - 1) * (n - 2) / 2 % MOD;
            long k = n / 2;
            long valid = k * (k - 1) / 2 % MOD;
            valid = valid * 3 % MOD;
            long ans = (MOD + total - valid) % MOD;
            ans = ans * quickPow(total, MOD - 2, MOD) % MOD;
            System.out.println(ans);
        }
    }
}
