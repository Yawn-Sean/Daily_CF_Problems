import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        List<List<Integer>> path = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            path.add(new ArrayList<>());
        }

        for (int i = 0; i < n - 1; i++) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            path.get(u).add(v);
            path.get(v).add(u);
        }

        int[] parent = new int[n];
        Arrays.fill(parent, -1);
        List<Integer> order = new ArrayList<>();
        Deque<Integer> stk = new ArrayDeque<>();
        stk.push(0);

        while (!stk.isEmpty()) {
            int u = stk.pop();
            order.add(u);

            for (int v : path.get(u)) {
                if (parent[u] != v) {
                    parent[v] = u;
                    stk.push(v);
                }
            }
        }

        long inf = (long) 1e15;

        long[] dp = new long[n];
        long[] dp1 = new long[n];
        long[] dp2 = new long[n];
        Arrays.fill(dp1, -inf);
        Arrays.fill(dp2, -inf);
        long ans = -inf;

        Collections.reverse(order);

        for (int i : order) {
            dp[i] += nums[i];
            if (i > 0) {
                int p = parent[i];
                dp[p] += dp[i];

                long v = Math.max(dp[i], dp1[i]);
                if (v >= dp1[p]) {
                    dp2[p] = v;
                    long temp = dp1[p];
                    dp1[p] = dp2[p];
                    dp2[p] = temp;
                } else if (v > dp2[p]) {
                    dp2[p] = v;
                }
            }

            if (dp2[i] > -inf) {
                ans = Math.max(ans, dp1[i] + dp2[i]);
            }
        }

        if (ans > -inf) {
            System.out.println(ans);
        } else {
            System.out.println("Impossible");
        }
    }
}
