
public class cf731f_Leoncn {
    private static void solve() {
        int n = sc.ni();
        int[] g = sc.na(n);
        int max = (int)2e5 + 5;
        int[] cnt = new int[max+2];
        for (int i = 0; i < n; i++) {
            cnt[g[i]+1]++;
        }
        for (int i = 0; i <=max; i++) {
            cnt[i+1] += cnt[i];
        }
        long[] ans = new long[max+1];
        for (int i = 1; i <=max ; i++) {
            for (int j = 0; j <=max; j+=i) {
                ans[i] += (long)j *(cnt[Math.min(max+1,j+i)] - cnt[j]);
            }
        }
        long res = 0;
        for (int i = 0; i <n; i++) {
            res = Math.max(res, ans[g[i]]);
        }
        out.println(res);
    }
}
