public class Main{
    private static void solve() throws IOException {
        int n = sc.nextInt();
        long x = sc.nextLong(), y = sc.nextLong();
        int[][] nums = new int[n][2];
        for (int i = 0; i < n; i++) {
            nums[i][0] = sc.nextInt();
            nums[i][1] = sc.nextInt();
        }
        Arrays.sort(nums, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        PriorityQueue<Integer> pq1 = new PriorityQueue<>((a, b) -> a - b); // 小根堆
        PriorityQueue<Integer> pq2 = new PriorityQueue<>((a, b) -> b - a);
        long ans = 0L;
        for (int i = 0; i < n; i++) {
            while (!pq1.isEmpty() && pq1.peek() < nums[i][0]) {
                pq2.offer(pq1.poll());
            }
            long add = x + (long) (nums[i][1] - nums[i][0]) * y;
            if (!pq2.isEmpty()) {
                Integer poll = pq2.poll();
                add = Math.min(add, (nums[i][1] - poll) * y);
            }
            pq1.offer(nums[i][1]);
            ans += add;
            ans %= Mod;
        }
        sc.print(ans);
    }
}
