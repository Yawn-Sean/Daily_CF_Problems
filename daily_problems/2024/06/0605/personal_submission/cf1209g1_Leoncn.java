public class cf1209g1_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int q = sc.ni();
        int[] g = sc.na(n);
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.putIfAbsent(g[i], new ArrayList<>());
            map.get(g[i]).add(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            List<Integer> list = map.get(g[i]);
            int maxLoc = list.get(list.size()-1);
            int max = list.size();
            int r = i;
            while (maxLoc> r){
                r++;
                List<Integer> f = map.get(g[r]);
                max = Math.max(f.size(), max);
                maxLoc = Math.max(maxLoc, f.get(f.size()-1));
            }
            ans += r-i+1 - max;
            i = r;
        }
        out.println(ans);
    }

}
