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
            int[] a = new int[n];
            int[] diff = new int[n + 2];
            for (int i = 0; i < n; i++) {
                a[i] = io.nextInt();
                diff[0]++;
                diff[Math.min(n, a[i])]--;
            }
            int[] b = new int[n + 1];
            b[0] = diff[0];
            for (int i = 1; i <= n; i++)
                b[i] = diff[i] + b[i - 1];
            long res = 0;
            for (int i = 0; i < n; i++) {
                int tmp = a[i] - Math.min(b[i], a[i]);
                res += tmp;
            }
            io.println(res);
        }

    }
