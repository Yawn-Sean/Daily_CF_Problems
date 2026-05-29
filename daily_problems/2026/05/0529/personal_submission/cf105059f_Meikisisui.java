public static void main(String[] args) {
        io = new IO();
//        int T = 1;
        int T = io.nextInt();
        while (T-- > 0) new Solution().solve();
        io.close();
    }

    static class Solution {

        void solve() {
            int n = io.nextInt();
            long[] a = new long[n], sum = new long[n + 1];
            for (int i = 0; i < n; i++) {
                a[i] = io.nextLong();
                sum[i + 1] = sum[i] + a[i];
            }
            double len = 0, tmp = 0;
            for (int i = 0; i < n; i++) {
                len += sum[n - i] - sum[i];
                tmp += len / (i + 1);
            }
            double res = tmp * 2 / n / (n + 1);
            io.println(res);
        }

    }
