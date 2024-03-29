public class cf891a_WindLY {
    public static void main(String[] args) throws IOException {
        int n = ni();
        int[] a = na();
        int min = Integer.MAX_VALUE;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int g = a[i];
            if (a[i] == 1) cnt++;
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, a[j]);
                if (g == 1) {
                    min = Math.min(min, j - i);
                    break;
                }
            }
        }
        if (min == Integer.MAX_VALUE) {
            if (cnt == n) out.println(0);
            else out.println(-1);
        }
        else out.println(n - 1 + min - cnt);
        out.flush();
    }
    static int gcd(int a, int b) {
        return a % b == 0 ? b : gcd(b, a % b);
    }
}