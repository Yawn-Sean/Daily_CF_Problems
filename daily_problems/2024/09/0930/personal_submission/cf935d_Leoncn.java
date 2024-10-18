
public class cf935d_Leoncn {
    static long mod = (long)1e9+7;
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int[] g = sc.na(n);
        int[] tar = sc.na(n);
        long inv2 = quickPowerMod(2, mod-2, mod);
        long invM = quickPowerMod( m, mod-2, mod);

        long ans = 0, prob = 1;
        for (int i = 0; i < n; i++) {
            if(g[i]>0){
                if(tar[i]>0){
                    if(g[i]>tar[i]){
                        ans += prob;
                        ans%=mod;
                        break;
                    }else if(g[i]<tar[i]){
                        break;
                    }
                }else {
                    ans += prob * (g[i] - 1) % mod * invM % mod;
                    ans%=mod;
                    prob = prob * invM % mod;
                }
            }else {
                if(tar[i]>0){
                    ans += prob * (m - tar[i]) % mod * invM % mod;
                    ans%=mod;
                    prob = prob * invM % mod;
                }else {
                    ans += prob * (m - 1) % mod * inv2 % mod * invM % mod;
                    ans%=mod;
                    prob = prob * invM % mod;
                }
            }
        }
        out.println(ans);

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
