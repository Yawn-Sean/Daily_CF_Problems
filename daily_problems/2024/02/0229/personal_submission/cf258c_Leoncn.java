
public class cf258c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] g = new int[n];
        int max = 1;
        for (int i = 0; i < n; i++) {
            int a = sc.ni();
            g[i] = a;
            if(a>max){
                max = a;
            }
        }
        long mod = (int)1e9+7;
        long[] cnt = new long[max+1];
        for (int i = 0; i < n; i++) {
            cnt[g[i]]++;
        }
        for (int i = max; i >0 ; i--) {
            cnt[i-1] += cnt[i];
        }
        ArrayList<Integer>[] f = new ArrayList[max+1];
        for (int i = 0; i <=max; i++) {
            f[i] = new ArrayList<>();
        }
        for (int i = 1; i <=max ; i++) {
            for (int j = i; j <=max ; j+=i) {
                f[j].add(i);
            }
        }
        long ans = 0;
        for (int i = 1; i <=max ; i++) {
            long res = 1;
            int k = f[i].size();
            for (int j = 1; j <k ; j++) {
                res = res*fastPower(j,cnt[f[i].get(j-1)]- cnt[f[i].get(j)], mod) % mod;
            }
            res = res *(fastPower(k, cnt[i], mod) - fastPower(k-1, cnt[i], mod)) % mod;
            ans += res;
        }
        out.println((ans%mod + mod)%mod);
    }
    public static long fastPower(long a, long n, long p) {
        long result = 1;  // 初始化结果
        long base = a % p;  // 将 a 模 p

        while (n > 0) {
            if ((n & 1) == 1) {  // 检查 n 的最低位是否为 1（即 n 是否为奇数）
                result = (result * base) % p;  // 如果是奇数，乘上当前的 base
            }
            base = (base * base) % p;  // 不断平方 base
            n >>= 1;  // 将 n 右移一位（即 n = n / 2）
        }

        return result;
    }
}
