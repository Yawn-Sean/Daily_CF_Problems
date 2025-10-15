import java.util.Scanner;

public class Main {

    public static long quickPow(long base, long power, long mod) {
        if (power == 0) return 1 % mod;
        long cur = quickPow(base, power / 2, mod);
        return (power & 1) != 0 ? (base * cur % mod * cur % mod) % mod : (cur * cur % mod);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long x, k;
        int mod = (int) (1e9 + 7);
        x = scanner.nextLong();
        k = scanner.nextLong();
        long result = x != 0 ? (((2 * x - 1) % mod * quickPow(2, k, mod) % mod + 1) % mod) : 0;
        System.out.println(result);
        scanner.close();
    }
}
