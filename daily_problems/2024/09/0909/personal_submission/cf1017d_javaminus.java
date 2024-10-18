    private static void solve() throws IOException {
        int n = sc.nextInt(), m = sc.nextInt(), q = sc.nextInt();
        int[] nums = new int[n];
        ss = sc.nextLine().split(" ");
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(ss[i]);
        }
        int[] cnt = new int[1 << n];
        for (int i = 0; i < m; i++) {
            s = sc.next();
            int mask = 0;
            for (char c : s.toCharArray()) {
                mask = mask * 2 + c - '0';
            }
            cnt[mask]++;
        }
        int[] dp = new int[1 << n];
        for (int i = 1; i < (1 << n); i++) {
            int x = i & (-i);
            dp[i] = dp[i - x] + nums[n - (32 - Integer.numberOfLeadingZeros(x))];
        }
        int[][] ans = new int[101][1 << n];
        int u = (1 << n) - 1;
        for (int x = 0; x < (1 << n); x++) {
            for (int y = 0; y < (1 << n); y++) {
                if (dp[u - (x ^ y)] <= 100) {
                    ans[dp[u - (x ^ y)]][x] += cnt[y];
                }
            }
            for (int y = 0; y < 100; y++) {
                ans[y + 1][x] += ans[y][x];
            }
        }
        while (q-- > 0) {
            s = sc.next();
            int k = sc.nextInt();
            int mask = 0;
            for (char c : s.toCharArray()) {
                mask = mask * 2 + c - '0';
            }
            sc.println(ans[k][mask]);
        }
    }
