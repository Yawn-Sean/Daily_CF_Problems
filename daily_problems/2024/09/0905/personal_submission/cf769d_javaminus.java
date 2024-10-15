public class Main{
    private static void solve() throws IOException {
        int n = sc.nextInt(), k = sc.nextInt();
        int[] nums = new int[n];
        int[] cnt = new int[1 << 14];
        ss = sc.nextLine().split(" ");
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(ss[i]);
            cnt[nums[i]]++;
        }
        long ans = 0L;
        if (k == 0) {
            for (int i = 0; i < (1 << 14); i++) {
                ans += (long) cnt[i] * (cnt[i] - 1) / 2;
            }
        }else{
            ArrayList<Integer> vals = new ArrayList<>();
            for (int i = 0; i < (1 << 14); i++) {
                if (Integer.bitCount(i) == k) {
                    vals.add(i);
                }
            }
            for (int i = 0; i < (1 << 14); i++) {
                for (int x : vals) {
                    ans += (long) cnt[i] * cnt[x ^ i];
                }
            }
            ans /= 2;
        }
        sc.println(ans);
    }
}
