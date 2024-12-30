

public class cf802b_Leoncn {
        public static void solve() {
        int n = sc.ni();
        int k = sc.ni();
        int[] g = sc.na(n);
        Map<Integer, Integer> map = new HashMap<>();
        int[] next = new int[n];
        for (int i = n-1; i >=0 ; i--) {
            next[i] = map.getOrDefault(g[i],i);
            map.put(g[i], i);
        }
        TreeSet<Integer> set = new TreeSet<>((a,b)->next[a] - next[b]);
        Map<Integer, Integer> have = new HashMap<>();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if(have.containsKey(g[i])){
                set.remove(have.get(g[i]));
            }else {
                if(k == have.size()){
                    have.remove(g[set.pollLast()]);
                }
                ans++;
            }
            have.put(g[i],i);
            set.add(i);
            if(next[i] == i){
                have.remove(g[i]);
                set.remove(i);
            }
        }
        out.println(ans);

    }
}
