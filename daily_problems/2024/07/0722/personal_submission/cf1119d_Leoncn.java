public class cf1119d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        long[] g = sc.nal(n);
        Arrays.sort(g);
        int q = sc.ni();
        long[] diffs = new long[n];
        for (int i=1; i<n; i++) {
            diffs[i] = g[i] - g[i-1];
        }
        Arrays.sort(diffs);
        long[] sum = new long[n];
        for (int i=1; i<n; i++) {
            sum[i] = sum[i-1] + diffs[i];
        }
        for (int i =0; i<q; i++) {
            long a = sc.nl();
            long b = sc.nl();
            long width = b-a+1;
            int low = 0;
            int high = n-1;
            while (low < high) {
                int mid = (low + high + 1)/2;
                if (width < diffs[mid]) {
                    high = mid-1;
                } else {
                    low = mid;
                }
            }
            long ans = (n-low)*width + sum[low];
            out.println(ans);
        }
    }
}
