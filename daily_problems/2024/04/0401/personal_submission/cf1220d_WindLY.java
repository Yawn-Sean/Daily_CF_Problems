public class cf1220d_WindLY {
    // 思路详见村长题解（
    // https://codeforces.com/contest/1220/submission/254398644
    public static void main(String[] args) throws IOException {
        int n = ni();
        long[] a = na();
        Map<Long, Set<Long>> map = new HashMap<>(); // cnt list
        Set<Long> set = new HashSet<>();
        for (long v: a) {
            long k = v & -v;
            map.computeIfAbsent(k, e -> new HashSet<>()).add(v);
        }
        for (Set<Long> t: map.values()) {
            if (set.size() < t.size()) set = t;
        }
        out.println(n - set.size());
        for (long v: a) {
            if (set.contains(v)) continue;
            out.print(v + " ");
        }
        out.flush();
    }
}
