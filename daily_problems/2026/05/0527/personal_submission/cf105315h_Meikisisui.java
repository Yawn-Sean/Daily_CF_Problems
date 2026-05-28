static class Solution {

        private static class Pair {
            long x;
            long y;

            Pair(long x, long y) {
                this.x = x;
                this.y = y;
            }
        }

        void solve() {
            int n = io.nextInt();
            int k = io.nextInt();
            Pair[] pairs = new Pair[n];
            for (int i = 0; i < n; i++) {
                long a = io.nextLong();
                long b = io.nextLong();
                pairs[i] = new Pair(a, b);
            }
            Arrays.sort(pairs, (a, b) -> {
                return Long.compare(a.y, b.y);
            });
            PriorityQueue<Long> pq = new PriorityQueue<>();
            long res = Long.MIN_VALUE, tmp = 0;
            for (Pair p : pairs) {
                long x1 = p.x, y1 = p.y;
                if (pq.size() == k - 1) res = Math.max(res, tmp + x1 - y1);
                tmp += x1;
                pq.add(x1);
                if (pq.size() == k) tmp -= pq.poll();
            }
            io.println(res);
        }

    }
