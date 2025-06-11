import java.util.*;

public class b1292 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long x0 = scanner.nextLong();
        long y0 = scanner.nextLong();
        int ax = scanner.nextInt();
        int ay = scanner.nextInt();
        long bx = scanner.nextLong();
        long by = scanner.nextLong();
        long xs = scanner.nextLong();
        long ys = scanner.nextLong();
        long t = scanner.nextLong();

        long x = x0, y = y0;
        List<Long> px = new ArrayList<>();
        List<Long> py = new ArrayList<>();

        while (x + y - xs - ys <= t) {
            px.add(x);
            py.add(y);
            x = x * ax + bx;
            y = y * ay + by;
        }

        int ans = 0;
        int n = px.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                for (int k = i; k < n; k++) {
                    if (Math.abs(xs - px.get(i)) + Math.abs(ys - py.get(i)) + px.get(k) - px.get(j) + py.get(k) - py.get(j) +
                            Math.min(px.get(k) - px.get(i) + py.get(k) - py.get(i), px.get(i) - px.get(j) + py.get(i) - py.get(j)) <= t) {
                        ans = Math.max(ans, k - j + 1);
                    }
                }
            }
        }

        System.out.println(ans);
    }
}
