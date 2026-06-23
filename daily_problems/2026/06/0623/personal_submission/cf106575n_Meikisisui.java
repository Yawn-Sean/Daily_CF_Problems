void solve() {
            int n = io.nextInt();
            long ca = io.nextLong(), cb = io.nextLong();
            int[] a = new int[n], b = new int[n];
            for (int i = 0; i < n; i++) {
                int tmp = io.nextInt();
                a[(tmp - 1) / 2] = i;
            }
            for (int i = 0; i < n; i++) {
                int tmp = io.nextInt();
                b[(tmp - 1) / 2] = i;
            }
            long res = Long.MAX_VALUE, mn = Long.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                mn = Math.min(mn, a[i]);
                res = Math.min(res, ca * mn + cb * b[i]);
            }
            io.println(res);
        }
