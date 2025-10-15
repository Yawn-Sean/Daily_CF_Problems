public class cf1201h {

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = scanner.nextInt();
        Pair[] wls = new Pair[n];
        long ans = 0;

        for (int i = 0; i < n; i++) {
            int first = scanner.nextInt();
            int second = scanner.nextInt();
            if (first > second) {
                int temp = first;
                first = second;
                second = temp;
            }
            wls[i] = new Pair(first, second);
            ans = Math.max(ans, 1L * first * second);
        }

        Arrays.sort(wls);

        int max_l = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans = Math.max(ans, 2L * wls[i].first * Math.min(wls[i].second, max_l));
            max_l = Math.max(max_l, wls[i].second);
        }

        out.print(ans / 2);
        out.print('.');
        out.print(ans % 2 * 5);

        out.flush();
    }

    static class Pair implements Comparable<Pair> {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair other) {
            if (this.first != other.first) {
                return Integer.compare(this.first, other.first);
            } else {
                return Integer.compare(this.second, other.second);
            }
        }
    }
}
