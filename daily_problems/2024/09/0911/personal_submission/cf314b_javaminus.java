public class Main{       
	private static void solve() throws IOException {
        int sn = sc.nextInt(), tn = sc.nextInt();
        String s = sc.next(), t = sc.next();
        int m = t.length();
        int[] toIdx = new int[m];
        int[] cnt = new int[m];
        Arrays.setAll(toIdx, i -> i);
        for (int i = 0; i < m; i++) {
            for (char ch : s.toCharArray()) {
                if (ch == t.charAt(toIdx[i])) {
                    toIdx[i]++;
                    if (toIdx[i] == m) {
                        cnt[i]++;
                        toIdx[i] = 0;
                    }
                }
            }
        }
        int idx = 0, cur = 0;
        while (sn-- > 0) {
            cur += cnt[idx];
            idx = toIdx[idx];
        }
        sc.println(cur / tn);
    }
}
