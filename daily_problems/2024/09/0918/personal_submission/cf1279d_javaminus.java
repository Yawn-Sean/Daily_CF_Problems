public static void main(String[] args) {
        int n = sc.nextInt();
        f[0] = 1;
        for (int i = 1; i <= M; i++) {
            f[i] = f[i - 1] * i % Mod;
        }

        g[M] = quickPow(f[M], Mod - 2, Mod);
        for (int i = M; i >= 1; i--) {
            g[i - 1] = g[i] * i % Mod;
        }

        List<List<Integer>> pools = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int k = sc.nextInt();
            List<Integer> pool = new ArrayList<>();
            for (int j = 0; j < k; j++) {
                int x = sc.nextInt();
                pool.add(x);
                cnt[x]++;
            }
            pools.add(pool);
        }

        long ans = 0;
        for (List<Integer> pool : pools) {
            int k = pool.size();
            for (int v : pool) {
                ans = (ans + cnt[v] * inv(k) % Mod) % Mod;
            }
        }

        System.out.println(ans * inv(n) % Mod * inv(n) % Mod);
    }
}
