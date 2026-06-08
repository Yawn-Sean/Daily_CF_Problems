void solve() {
            int n = io.nextInt();
            int x = io.nextInt();
            int y = io.nextInt();
            PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> {
                return Double.compare(a[0], b[0]);
            });
            for (int i = 0; i < n; i++) {
                double x1 = io.nextDouble(), y1 = io.nextDouble(), r = io.nextDouble();
                double juli = Math.sqrt((y1 - y) * (y1 - y) + (x1 - x) * (x1 - x)) - r;
                pq.add(new double[]{juli, r});
            }
            double res = 0, sum = 0;
            while (!pq.isEmpty()) {
                double[] cur = pq.poll();
                res = Math.max(res, cur[0] - sum);
                sum += cur[1];
            }
            io.println(res);
        }
