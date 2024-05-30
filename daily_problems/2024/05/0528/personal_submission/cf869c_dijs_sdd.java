import java.util.Scanner;

public class cf869C {
    public static void main(String[] args) {
        int mod = 998244353;
        Factorial fac = new Factorial(5001, mod);
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();

        System.out.println((f(a, b, fac, mod) * f(b, c, fac, mod) % mod * f(a, c, fac, mod) % mod));
    }

    private static long f(int x, int y, Factorial fac, int mod) {
        long ans = 0;
        for (int i = 0; i <= Math.min(x, y); i++) {
            ans += (fac.combi(x, i) * fac.combi(y, i) % mod * fac.fac(i) % mod);
            ans %= mod;
        }
        return ans;
    }
}

class Factorial {
    private long[] factorial;
    private long mod;

    public Factorial(int n, long mod) {
        this.mod = mod;
        factorial = new long[n + 1];
        factorial[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorial[i] = (factorial[i - 1] * i) % mod;
        }
    }

    public long combi(int n, int k) {
        return (factorial[n] * pow(factorial[k], mod - 2, mod) % mod * pow(factorial[n - k], mod - 2, mod) % mod);
    }

    public long pow(long base, long exp, long mod) {
        long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            exp >>= 1;
            base = (base * base) % mod;
        }
        return result;
    }

    public long fac(int n) {
        return factorial[n];
    }
}
