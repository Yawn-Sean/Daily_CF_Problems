public class cf1114c_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    public static void solve() {
        long n = sc.nl();
        long b = sc.nl();
        List<Long> list = getPrimeFactors(b);
        Map<Long, Long> map = new HashMap<>();

        for(long l: list){
            long cnt = 0;
            while (b%l==0){
                b/=l;
                cnt++;
            }
            map.put(l, cnt);
        }

        long ans = Long.MAX_VALUE;
        for(long l: list){
            long tem = n;
            long cnt = 0;
            while (tem>=l){
                cnt += tem/l;
                tem/=l;
            }
            ans = Math.min(cnt/map.get(l),ans);
        }
        out.println(ans);

    }
    static final List<Integer> PRIMES = getPrimesLe(1000001);

    public static List<Integer> getPrimesLe(int n) {
        boolean[] arr = new boolean[n+1];
        Arrays.fill(arr, true);
        arr[1] = false;
        int p = 2;
        int r = (int) (1 + Math.sqrt(n));
        while (p <= r) {
            int v = p + p;
            while (v <= n) {
                arr[v] = false;
                v += p;
            }
            p++;
            while (p <= r && !arr[p]) {
                p++;
            }
        }

        List<Integer> primes = new ArrayList<>();
        for (int i = 2; i <= n; i++) {
            if (arr[i]) {
                primes.add(i);
            }
        }
        //show(primes);
        return primes;
    }

    /**
     ** 获取质数因子
     * */
    public static List<Long> getPrimeFactors(long k) {
        List<Long> ans = new ArrayList<>();
        long r = (long) Math.sqrt(k) + 1;
        for (long p : PRIMES) {
            if (p > r) {
                break;
            }
            int exp = 0;
            while (k % p == 0) {
                exp++;
                k /= p;
            }
            if (exp > 0) {
                ans.add(p);
            }
        }
        if (k != 1) {
            ans.add(k);
        }
        return ans;
    }
}
