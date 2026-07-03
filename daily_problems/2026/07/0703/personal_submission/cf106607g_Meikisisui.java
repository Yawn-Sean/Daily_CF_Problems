        void solve() {
            long n = io.nextLong(), m = io.nextLong(), k = io.nextLong();
            if (k > m * n) {
                io.println(0);
                return;
            }
            if (k <= n) {
                io.println(k);
                return;
            }
            long res = n;
            if ((n - k & 1) == 1)
                res--;
            if ((m & 1) == 0)
                res = Math.min(res, m * n - k);
            io.println(res);
        }
