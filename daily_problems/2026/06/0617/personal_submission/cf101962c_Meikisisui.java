void solve() {
            long n = io.nextLong();
            long tmp = (n - 3) % MOD7;
            tmp = (tmp * quickPow(2, n, MOD7)) % MOD7;
            tmp = (tmp + n + 3) % MOD7;
            io.println(tmp);
        }

        private long quickPow(long a, long b, int p) {
            // 防止p=1，否则返回0
            long res = 1 % p;
            while (b > 0) {
                // b最后一位是否是1
                if ((b & 1) == 1)
                    res = res * a % p;
                a = (a * a % p);
                // 删除b最后一位
                b >>= 1;
            }
            return res;
        }
