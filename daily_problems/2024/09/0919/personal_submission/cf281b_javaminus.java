    private static void solve() throws IOException {
        long x = sc.nextInt(), y = sc.nextInt(), n = sc.nextInt();
        long g = gcd(x, y);
        x /= g;
        y /= g;
        if (n >= y) {
            sc.println(x + "/" + y);
            return;
        }
        double target = (double) x / y, ans = target;
        long a0 = 0, b0 = 0;
        for (int b = (int) n; b >= 0; b--) {
            int c = (int) (target * b);
            for (int a = c + 1; a >= Math.max(0, c - 1); a--) {
                if (Math.abs((double) a / b - target) - ans < 0.000000000000001) {
                    ans = Math.abs((double) a / b - target);
                    a0 = a;
                    b0 = b;
                }
            }
        }
        sc.println(a0 + "/" + b0);
    }

    private static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
