
    private static int[] sum, ji;

    private static void init() {
        int m = 100001;
        sum = new int[100001];
        for (int i = 1; i < m; i++) {
            for (int j = i * 2; j < m; j += i)
                sum[j]++;
        }
        for (int i = 1; i < m; i++)
            sum[i] += sum[i - 1];
        ji = new int[m];
        ji[0] = 1;
        for (int i = 1; i < m; i++)
            ji[i] = (int) ((long) i * ji[i - 1] % MOD7);
    }

    static class Solution {

        void solve() {
            int n = io.nextInt();
            int ni = (MOD7 + 1) / 2;
            long ans = (long) sum[n] * ni % MOD7;
            ans = ans * ji[n] % MOD7;
            io.println(ans);
        }

    }
