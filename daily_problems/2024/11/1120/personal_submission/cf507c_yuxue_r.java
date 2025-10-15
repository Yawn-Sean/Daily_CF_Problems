import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int h;
        long n;
        h = scanner.nextInt();
        n = scanner.nextLong();
        LongFunction f = new LongFunction();
        System.out.println(f.compute(1, 1L << h, 0, h, n));
        scanner.close();
    }

    static class LongFunction {
        public long compute(long l, long r, int curStep, int height, long n) {
            if (height == 0) return 0;
            long m = l + (r - l) / 2;
            long ans = ((n <= m) == (curStep == 1) ? 1L << height : 1);
            ans += (n <= m ? compute(l, m, 1, height - 1, n) : compute(m + 1, r, 0, height - 1, n));
            return ans;
        }
    }
}
