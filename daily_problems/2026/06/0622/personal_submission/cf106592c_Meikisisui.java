void solve() {
            long n = io.nextLong();
            int k = io.nextInt();
            long[] a = new long[k];
            for (int i = 0; i < k; i++)
                a[i] = io.nextLong();
            long left = 0, right = 1000000001;
            while (left < right) {
                long mid = left + (right - left) / 2;
                long sum = 0;
                for (long tmp : a)
                    sum += Math.min(tmp, mid);
                if (sum > n)
                    right = mid;
                else
                    left = mid + 1;
            }
            long val = (left == 0) ? 0 : left - 1;
            long[] b = new long[k];
            for (int i = 0; i < k; i++) {
                b[i] = Math.min(a[i], val);
                n -= b[i];
            }
            for (int i = 0; i < k; i++) {
                if (a[i] > b[i] && n > 0) {
                    n--;
                    b[i]++;
                }
                io.print(b[i] + " ");
            }
            io.println();
        }
