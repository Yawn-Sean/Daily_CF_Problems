public class Main{
    private static void solve() throws IOException {
        int n = sc.nextInt(), m = sc.nextInt();
        ss = sc.nextLine().split(" ");
        int[] nums = new int[m];
        for (int i = 0; i < m; i++) {
            nums[i] = Integer.parseInt(ss[i]);
        }
        long sum = 0, res = 0;
        List<Integer>[] g = new List[n + 1];
        long[] cur = new long[n + 1];
        Arrays.setAll(g, e -> new ArrayList<>());
        for (int i = 1; i < m; i++) {
            int v = Math.abs(nums[i] - nums[i - 1]);
            sum += v;
            if (nums[i] != nums[i - 1]) {
                cur[nums[i]] += v;
                cur[nums[i - 1]] += v;
                g[nums[i]].add(nums[i - 1]);
                g[nums[i - 1]].add(nums[i]);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!g[i].isEmpty()) {
                Collections.sort(g[i]);
                int mid = g[i].get(g[i].size() / 2);
                long cur_sum = 0;
                for (int x : g[i]) {
                    cur_sum += Math.abs(x - mid);
                }
                res = Math.max(res, cur[i] - cur_sum);
            }
        }
        sc.println(sum - res);
    }
}
