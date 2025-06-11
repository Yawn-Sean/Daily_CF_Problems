
public class cf1279d_Leoncn {
    static long mod = 998244353;
    public static void solve() {
        int n = sc.ni();
        Map<Integer, Long> map = new HashMap<>();
        Map<Integer, Long> cnt = new HashMap<>();
        long nInv = quickPowerMod(n, mod-2, mod);
        for (int i = 0; i < n; i++) {
            long k = sc.ni();
            long kInv = k==1?k:quickPowerMod(k, mod-2,mod);
            for (int j = 0; j < k; j++) {
                int p = sc.ni();
                map.merge(p, nInv*kInv%mod, Long::sum);
                cnt.merge(p, 1L, Long::sum);
            }
        }
        long ans = 0;
        for(int k: map.keySet()){
            ans = (ans + map.get(k)%mod * nInv % mod * cnt.get(k) % mod)%mod;
        }
        out.println(ans%mod);
    }
    public static long quickPowerMod(long a, long b, long c) {
        long result = 1;
        a = a % c; // 确保a是在模c的范围内
        while (b > 0) {
            if ((b & 1) == 1) { // 判断b的二进制表示的最后一位是不是1
                result = (result * a) % c;
            }
            b >>= 1; // 将b右移一位，相当于除以2
            a = (a * a) % c; // 将a平方，同时保持a是在模c的范围内
        }
        return result;
    }
}
