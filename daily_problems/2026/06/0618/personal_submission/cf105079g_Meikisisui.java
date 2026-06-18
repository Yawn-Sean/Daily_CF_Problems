void solve() {
            int n = io.nextInt();
            long[] a = new long[n], b = new long[n];
            long res = 0, sum = 0;
            PriorityQueue<Long> pq = new PriorityQueue<>((a1, b1) -> {
                return Long.compare(b1, a1);
            });
            for (int i = 0; i < n; i++) {
                a[i] = io.nextLong();
                res += a[i];
                pq.offer(a[i]);
            }
            for (int i = 0; i < n; i++) {
                b[i] = io.nextLong();
                sum += b[i];
                long tmp = pq.poll() + sum;
                res += b[i] * n - tmp / 2;
                tmp -= tmp / 2;
                pq.offer(tmp - sum);
            }
            io.println(res);
        }
