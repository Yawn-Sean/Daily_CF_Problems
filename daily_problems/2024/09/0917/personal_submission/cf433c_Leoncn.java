
public class cf433c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int[] g = sc.na(m);
        long[] cnt = new long[n+1];
        List<Integer>[] arr = new ArrayList[n+1];
        for (int i = 0; i < n+1; i++) {
            arr[i] = new ArrayList<>();
        }

        long ans = 0;
        for (int i = 0; i < m-1; i++) {
            if(g[i+1]== g[i]) continue;
            int ma = Math.abs(g[i+1] - g[i]);
            ans += ma;
            cnt[g[i+1]] += ma;
            cnt[g[i]] += ma;
            arr[g[i+1]].add(g[i]);
            arr[g[i]].add(g[i+1]);
        }
        long max = 0;
        for (int i = 1; i <= n; i++) {
            List<Integer> list = arr[i];
            if(list.size() == 0) continue;
            Collections.sort(list);
            int s = list.get(list.size()/2);
            long res = 0;
            for(int l: list){
                res += Math.abs(l - s);
            }
            max = Math.max(cnt[i]- res, max);
        }
        out.println(ans - max);
    }
}
