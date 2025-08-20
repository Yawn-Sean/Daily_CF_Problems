public class Main {
    static long ma, se;
    static int n, m, k;
    static long y1, y2;
    static long[] As, Ds, Fs;

    public static boolean check(long d){
        if (y2-d > y1+d) return false;
        long l = y2-d, r = y1+d;

        int j = k-1;
        for (int i = 0; i < m; ++ i){
            long x = Ds[i];
            while (j-1 >= 0 && x + Fs[j-1] >= l) j -= 1;

            if (x + Fs[j] >= l && x + Fs[j] <= r) return true;
        }

        return false;
    }


    public static void solve(){
        n = sc.nextInt();
        m = sc.nextInt();
        k = sc.nextInt();

        As = new long[n];
        Ds = new long[m];
        Fs = new long[k];

        for (int i = 0; i < n; ++ i){
            As[i] = sc.nextLong();
        }
        for (int i = 0; i < m; ++ i) {
            Ds[i] = sc.nextLong();
        }
        for (int i = 0; i < k; ++ i){
            Fs[i] = sc.nextLong();
        }

        ma = 0;
        se = 0;
        for (int i = 1; i < n; ++ i){
            long d = As[i] - As[i-1];
            if (d > ma){
                se = ma;
                ma = d;
                y1 = As[i-1];
                y2 = As[i];
            } else if (d > se){
                se = d;
            }
        }

        if (ma == 1){
            out.println(1);
            return;
        }

        Arrays.sort(Ds);
        Arrays.sort(Fs);
        Ds = Arrays.stream(Ds).boxed().sorted().mapToLong(Long::longValue).toArray();
        Fs = Arrays.stream(Fs).boxed().sorted().mapToLong(Long::longValue).toArray();

        long lo = se, hi = ma;
        while (lo < hi){
            long mid = (lo + hi) / 2;
            if (check(mid)) hi = mid;
            else lo = mid+1;
        }

        out.println(lo);
    }
}
