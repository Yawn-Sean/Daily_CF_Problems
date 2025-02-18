public class Main {
    public static void main(String[] args) throws IOException {
        // int T = sc.nextInt();
        while (T-- > 0) {
            solve();
            // sc.bw.flush();
        }
        sc.bw.flush();
        sc.bw.close();
    }

    private static String[] ss;
    private static String s;

    private static void solve() throws IOException {
        long n = sc.nextLong(), m = sc.nextLong(), k = sc.nextLong();
        if (m + n - 2 < k) {
            sc.println(-1);
            return;
        }
        if (n % (k + 1) == 0) {
            sc.println(m * (n / (k + 1)));
        } else if (m % (k + 1) == 0) {
            sc.println(n * (m / (k + 1)));
        }else{
            long ans = 0;
            // 先横切
            if (n >= k + 1) {
                long d1 = n / (k + 1);
                ans = d1 * m;
            }else{
                long p = k - (n - 1);
                long d2 = m / (p + 1);
                ans = Math.max(ans, d2);
            }
            if (m >= k + 1) {
                long d2 = m / (k + 1);
                ans = Math.max(ans, d2 * n);
            }else{
                long p = k - (m - 1);
                long d2 = n / (p + 1);
                ans = Math.max(ans, d2);
            }
            sc.println(ans);
        }
    }
}
