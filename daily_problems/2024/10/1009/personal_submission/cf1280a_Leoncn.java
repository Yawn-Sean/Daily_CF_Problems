
public class cf1280a_Leoncn {
    public static void solve() {
        int mod = (int)1e9+7;
        int x = sc.ni();
        char[] cs = sc.ns().toCharArray();
        int n = cs.length;
        int[] cnt = new int[x];
        int min = Math.min(x, n);
        for (int i = 0; i < min; i++) {
            cnt[i] = cs[i]-'0';
        }
        int loc = min;
        long sum = n;
        for (int i = 0; i < x; i++) {
            long addLen = (long)(cnt[i]-1) *((sum - i-1 + mod)%mod) %mod;

            long max = loc + addLen;
            while (loc < x && loc<max){
                cnt[loc] = cnt[loc-(int)(sum - i-1)];
                loc ++;
            }
            sum = (sum + addLen)%mod;
        }
        out.println(sum);

    }
}
