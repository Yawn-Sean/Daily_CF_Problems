void solve() {
            int n = io.nextInt(), k = io.nextInt();
            if (n == 2) {
                if ((k & -k) == k)
                    io.println(1);
                else
                    io.println(0);
            } else {
                int tmp = k - n;
                if (n % 2 == 0 && k == n + n / 2 + 1)
                    io.println(1);
                else
                    io.println(Math.max(0, n - 1 - 2 * tmp));
            }
        }
