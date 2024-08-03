
import java.util.Scanner;

public class k1575 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long m = scanner.nextLong();
        long k = scanner.nextLong();
        long r = scanner.nextLong();
        long c = scanner.nextLong();
        long ax = scanner.nextLong();
        long ay = scanner.nextLong();
        long bx = scanner.nextLong();
        long by = scanner.nextLong();

        long mod = 1000000007;
        int key = (ax != bx) || (ay != by)? 1:0;
        System.out.println(powMod(k, (n * m - r * c * key), mod));
    }

    // 辅助函数，用于计算幂并进行模运算
    private static long powMod(long base, long exponent, long mod) {
        long result = 1;
        base = base % mod;
        while (exponent > 0) {
            if ((exponent & 1) == 1) {
                result = (result * base) % mod;
            }
            exponent >>= 1;
            base = (base * base) % mod;
        }
        return result;
    }
}
