public class Main{
      private static void solve() throws IOException {
        long n = sc.nextLong();
        long a = 2, b = 1;
        long ans = 0;
        while (a <= n) {
            a += b;
            b = a - b;
            ans++;
        }
        sc.println(ans);
    }
}
