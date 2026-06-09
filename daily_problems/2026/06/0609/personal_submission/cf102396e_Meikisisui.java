void solve() {
            int n = io.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++)
                nums[i] = io.nextInt();
            long m = 0;
            long x = 1L << (n - 1);
            long[] res = new long[n];
            for (int i = 0; i < n; i++) {
                if (nums[i] != 0) {
                    res[i] = x / nums[i];
                    m += x;
                    x >>= 1;
                }
            }
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    res[i] = x;
                    x /= 2;
                }
            }
            io.println(m);
            for (int i = 0; i < n; i++)
                io.print(res[i] + " ");
        }
