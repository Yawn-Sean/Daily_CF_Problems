
public class cf626d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] g = sc.na(n);
        long[] cnt = new long[5000];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                cnt[Math.abs(g[i] - g[j])]++;
            }
        }
        long[] cnt2 = new long[5000];
        for (int i = 0; i < 5000; i++) {
            for (int j = 0; j < 5000 -i; j++) {
                cnt2[i+j] += cnt[i] * cnt[j];
            }
        }
        for (int i = 1; i <5000 ; i++) {
            cnt2[i] += cnt2[i-1];
        }
        double ans = 0;
        for (int i = 1; i < 5000; i++) {
            ans += cnt[i] * cnt2[i-1];
        }
        out.println(ans/ Math.pow(n*(n-1)/2,3));
    }

}
