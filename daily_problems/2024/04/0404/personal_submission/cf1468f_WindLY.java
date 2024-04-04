public class cf1468f_WindLY {
    // 向量相反的可以看到对方，哈希表统计
    // https://codeforces.com/contest/1468/submission/254913988
    public static void main(String[] args) throws IOException {
        int t = ni();
        while (t-- > 0) {
            int n = ni();
            Map<Double, Integer> map1 = new HashMap<>();
            Map<Double, Integer> map2 = new HashMap<>();
            long cnt = 0;
            for (int i = 0; i < n; i++) {
                int[] in = na();
                int a = in[0], b = in[1], u = in[2], v = in[3];
                int x = u - a, y = v - b;
                double k = (double) y / x;
                if (k == 0) k = 0;
                if (x == 0) k = Double.MAX_VALUE;
                cnt += x > 0 || x == 0 && y > 0 ? map2.getOrDefault(k, 0) : map1.getOrDefault(k, 0);
                if (x > 0 || x == 0 && y > 0) map1.merge(k, 1, Integer::sum);
                else map2.merge(k, 1, Integer::sum);
            }
            out.println(cnt);
        }
        out.flush();
    }
}