
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

/**
 * @Description:
 * @Author: Leon
 * @Date: 2024/4/5
 */
public class F {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-->0){
            int n = in.nextInt();
            TreeMap<Pair, Integer> map = new TreeMap<>();
            for (int i = 0; i < n; i++) {
                int x1 = in.nextInt();
                int y1 = in.nextInt();
                int dx = in.nextInt() - x1;
                int dy = in.nextInt() - y1;
                int gcd = (int) gcd(Math.abs(dx), Math.abs(dy));
                dx /= gcd;
                dy /= gcd;
                Pair cur = new Pair(dx, dy);
                if (map.containsKey(cur)) {
                    map.put(cur, map.get(cur) + 1);
                } else {
                    map.put(cur, 1);
                }
            }
            long ans = 0;
            for (Map.Entry<Pair, Integer> e : map.entrySet()) {
                if (map.containsKey(new Pair(-e.getKey().x, -e.getKey().y))) {
                    ans += (long) map.get(new Pair(-e.getKey().x, -e.getKey().y)) * e.getValue();
                }
            }
            System.out.println(ans / 2);
        }
    }
    public static long  gcd(long x, long y) {
        if (y == 0) {
            return x;
        }
        if (x == 0) {
            return y;
        }
        return gcd(y, x % y);
    }


    public static class Pair implements Comparable<Pair> {
        int x;
        int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public Pair clone() {
            return new Pair(x, y);
        }

        @Override
        public int compareTo(Pair o) {
            if (x > o.x) {
                return 1;
            }
            if (x < o.x) {
                return -1;
            }
            if (y > o.y) {
                return 1;
            }
            if (y < o.y) {
                return -1;
            }
            return 0;
        }

    }


}