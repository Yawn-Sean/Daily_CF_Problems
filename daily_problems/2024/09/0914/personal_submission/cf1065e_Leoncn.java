
public class cf1065e_Leoncn {
    private static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int a = sc.ni();
        int[] g = sc.na(m);
        int mod = 998244353;
        long ans = 1;
        int pre = 0;
        for(int num: g){
            long p = quickPowerMod(a, num - pre, mod);
            ans = ans * (p * (p + 1) /2 %mod)%mod ;
            pre = num;
        }
        ans = ans * quickPowerMod(a, n- g[m-1]*2,mod) %mod;
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
