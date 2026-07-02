
        void solve() {
            int n = io.nextInt();
            int[] a = new int[n];
            int left = n, right = -1;
            for (int i = 0; i < n; i++) {
                a[i] = io.nextInt();
                if (a[i] != 1) {
                    left = Math.min(left, i);
                    right = Math.max(right, i);
                }
            }
            if (left > right) {
                io.println(0);
                return;
            }
            for (int i = left; i <= right; i++) {
                if (a[i] != a[left]) {
                    io.println(2);
                    return;
                }
            }
            io.println(1);
        }
