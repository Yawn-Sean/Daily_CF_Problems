public class Main{
    private static void solve() throws IOException {
        n = sc.nextInt();
        long x1 = sc.nextLong(), x2 = sc.nextLong();
        long[][] pairs = new long[n][2];
        for (int i = 0; i < n; i++) {
            int k = sc.nextInt(), b = sc.nextInt();
            pairs[i][0] = k * x1 + b;
            pairs[i][1] = k * x2 + b;
        }
        Arrays.sort(pairs, (a, b) -> a[0] == b[0] ? Long.compare(a[1], b[1]) : Long.compare(a[0], b[0]));
        for (int i = 1; i < n; i++) {
            if (pairs[i][1] < pairs[i - 1][1]) {
                sc.println("YES");
                return;
            }
        }
        sc.println("NO");
    }
}
