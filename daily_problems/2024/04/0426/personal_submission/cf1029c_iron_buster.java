public class Main {

    // https://codeforces.com/problemset/problem/1029/C
    // https://codeforces.com/contest/1029/submission/258176653
    public static void solve() throws Exception {
        int n = in.nextInt();
        var a = new long[n][2];
        long maxLeft = Long.MIN_VALUE / 2;
        long minRight = Long.MAX_VALUE / 2;
        var map1 = new TreeMap<Long, Integer>();
        var map2 = new TreeMap<Long, Integer>();
        for (int i = 0; i < n; i++) {
            long l = in.nextLong();
            long r = in.nextLong();
            a[i][0] = l;
            a[i][1] = r;
            maxLeft = Math.max(maxLeft, l);
            minRight = Math.min(minRight, r);
            map1.merge(l, 1, Integer::sum);
            map2.merge(r, 1, Integer::sum);
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            long l = a[i][0], r = a[i][1];
            if (l == maxLeft && map1.get(l) == 1) {
                map1.remove(l);
                if (r == minRight && map2.get(r) == 1) {
                    map2.remove(r);
                    ans = Math.max(ans, map2.firstKey() - map1.lastKey());
                    map2.put(r, 1);
                } else {
                    ans = Math.max(ans, minRight - map1.lastKey());
                }
                map1.put(l, 1);
            } else {
                if (r == minRight && map2.get(r) == 1) {
                    map2.remove(r);
                    ans = Math.max(ans, map2.firstKey() - maxLeft);
                    map2.put(r, 1);
                } else {
                    ans = Math.max(ans, minRight - maxLeft);
                }
            }
        }
        out.println(ans);
    }
}
