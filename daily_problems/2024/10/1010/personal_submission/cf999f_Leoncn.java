
public class cf999f_Leoncn {
    public static void solve() {
        int max = (int)1e5+6;
        int n = sc.ni();
        int k = sc.ni();
        int[] cnt = new int[max];
        for (int i = 0; i < n*k; i++) {
            cnt[sc.ni()]++;
        }
        int[] c = new int[max];
        for (int i = 0; i < n; i++) {
            c[sc.ni()]++;
        }
        int[] v = sc.na(k);
        long ans = 0;
        for (int i = 0; i < max; i++) {
            if(c[i]>0){
                ans += sum(v, c[i], cnt[i]);
            }
        }
        out.println(ans);
    }

    private static long sum(int[] v, int s, int sum){
        long[] dp = new long[sum+1];
        Arrays.fill(dp, Long.MIN_VALUE/10);
        dp[0] = 0;
        for (int i = 0; i < s; i++) {

            for (int j = sum-1; j >=0; j--) {
                for (int k = 0; k < v.length; k++) {
                    if(j+k+1>sum) continue;
                    dp[j+k+1] = Math.max(dp[j] + v[k], dp[j+k+1]);
                }
            }
        }
        return dp[Math.min(sum, s*v.length)];
    }

}
