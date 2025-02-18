import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            ans ^= x;
        }

        java.util.function.IntUnaryOperator prefXor = x -> {
            if (x % 4 == 0) return x;
            else if (x % 4 == 1) return 1;
            else if (x % 4 == 2) return x + 1;
            return 0;
        };

        for (int i = 1; i <= n; i++) {
            int x = n % (2 * i);
            if (x >= i) ans ^= prefXor.applyAsInt(i - 1) ^ prefXor.applyAsInt(x - i);
            else ans ^= prefXor.applyAsInt(x);
        }

        System.out.println(ans);
        scanner.close();
    }
}
