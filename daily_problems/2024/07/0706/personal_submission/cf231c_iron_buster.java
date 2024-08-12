public class Main {

//    https://codeforces.com/problemset/problem/231/C

    public static void solve() throws Exception {
        int n = in.nextInt();
        int k = in.nextInt();
        long[] a = new long[n], s = new long[n+1];
        var group = new HashMap<Long, int[]>();
        for (int i = 0; i < n; i++) a[i] = in.nextLong();
        Arrays.sort(a);
        for (int i = 0; i < n; i++) {
            s[i+1] = s[i] + a[i];
            if (group.containsKey(a[i])) {
                group.get(a[i])[1] = i;
            } else {
                group.put(a[i], new int[]{i, i});
            }
        }
        // 枚举a[i]作为答案
        long mx = 0, ans = 0;
        for (var x : group.keySet()) {
            var b = group.get(x);
            int l = b[0], r = b[1];
            if (r - l + 1 > mx || (r - l + 1 == mx && x < ans)) {
                mx = r - l + 1;
                ans = x;
            }
            // 二分这个left
            int left = 0, right = l - 1;
            while (left < right) {
                int mid = (left + right) >> 1;
                long need = (l - mid) * x - (s[l] - s[mid]);
                if (need <= k) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            long need = (l - left) * x - (s[l] - s[left]);
            long cnt = r - left + 1;
            if (need <= k && (cnt > mx || (cnt == mx && x < ans))) {
                mx = cnt;
                ans = x;
            }
        }
        out.println(mx + " " + ans);
    }

    static boolean MULTI_CASE = false;

    public static void main(String[] args) throws Exception {
        int T = MULTI_CASE ? in.nextInt() : 1;
        while (T-- > 0) {
            solve();
        }
        out.close();
    }
}
