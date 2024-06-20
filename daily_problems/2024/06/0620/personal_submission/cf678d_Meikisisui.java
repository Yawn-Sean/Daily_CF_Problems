import java.util.Scanner;

public class Test1 {

    public static void main(String[] args) throws Exception {
        Test1 test = new Test1();
        Scanner sc = new Scanner(System.in);
        long a = sc.nextInt();
        long b = sc.nextInt();
        long n = sc.nextLong();
        long x = sc.nextInt();
        int res = test.iteratedLinear(a, b, n, x);
        System.out.println(res);
    }

    private long MOD = 1_000_000_007;

    public int iteratedLinear(long a, long b, long n, long x) {
        if (0 == n)
            return (int) x;
        if (1 == n)
            return (int) (((a * x) % MOD + b) % MOD);
        if (1 == a)
            return (int) (((b * (n % MOD)) % MOD + x) % MOD);
        long a1 = (quickPow(a, n) - 1 + MOD) % MOD;
        a1 = (a1 * modInverse(a - 1, MOD)) % MOD;
        a1 = (a1 * b) % MOD;
        long a2 = quickPow(a, n) * x % MOD;
        return (int) ((a1 + a2) % MOD);
    }

    private long quickPow(long i, long n) {
        if (0 == n)
            return 1;
        long res = quickPow(i, n / 2) % MOD;
        if (n % 2 == 0)
            return (res * res) % MOD;
        else
            return ((res * res) % MOD * i) % MOD;
    }

    private long modInverse(long a, long m) {
        long m0 = m;
        long y = 0, x = 1;
        if (m == 1) return 0;
        while (a > 1) {
            long q = a / m;
            long t = m;
            m = a % m;
            a = t;
            t = y;
            y = x - q * y;
            x = t;
        }
        if (x < 0) x += m0;
        return x;
    }

}
