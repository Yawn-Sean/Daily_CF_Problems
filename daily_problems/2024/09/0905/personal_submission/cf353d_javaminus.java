public class Main{
	private static void solve() throws IOException {
        cs = sc.next().toCharArray();
        int n = cs.length, cntM = 0;
        long ans = 0L;
        for (int i = 0; i < n; i++) {
            if (cs[i] == 'M') {
                cntM++;
            } else if (cntM > 0) {
                ans = Math.max(ans + 1, cntM);
            }
        }
        sc.println(ans);
    }
}
