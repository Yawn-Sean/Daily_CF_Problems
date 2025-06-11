
public class cf1660e_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] cnt = new int[n];
        for (int i = 0; i < n; i++) {
            char[] cs = sc.ns().toCharArray();
            for (int j = 0; j < n; j++) {
                cnt[(j-i + n)%n] += cs[j]-'0';
            }
        }
        int max = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            max = Math.max(max, cnt[i]);
            sum += cnt[i];
        }
        out.println(sum + n - max * 2);

    }

}
