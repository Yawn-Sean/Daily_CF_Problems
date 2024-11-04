    private static void solve() throws IOException {
        int n = sc.nextInt(), t = sc.nextInt();
        int[] nums = new int[n];
        int[] ts = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
            ts[i] = sc.nextInt();
        }
        int ans = 0, tot = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        Integer[] order = new Integer[n];
        for (int i = 0; i < n; i++) {
            order[i] = i;
        }
        Arrays.sort(order, (a, b) -> nums[b] - nums[a]);
        for (int i : order) {
            pq.add(ts[i]);
            tot += ts[i];
            if (tot > t) {
                tot -= pq.poll();
            }
            ans = Math.max(ans, Math.min(pq.size(), nums[i]));
        }
        sc.println(ans);
        sc.println(ans);
        int cnt = 0;
        Arrays.sort(order, (a, b) -> ts[a] - ts[b]);
        for (int i : order) {
            if (nums[i] >= ans && cnt < ans) {
                cnt++;
                sc.println((i + 1) + " ");
            }
        }
    }
