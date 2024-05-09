public class cf1102e_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) {
        int t = 1;
        while (t-->0){
            solve();
        }
        out.close();
    }

    private static void solve() {
        int mod = 998244353;
        int n = sc.ni();
        int[] g = sc.na(n);
        Map<Integer,Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.put(g[i],i);
        }
        Set<Integer> set = new HashSet<>();
        long ans = 1;
        set.add(g[0]);
        int max = map.get(g[0]);
        for (int i = 1; i < n; i++) {
            if(!set.contains(g[i])){
                if(i>max){
                    ans = ans * 2 %mod;
                }
                set.add(g[i]);
            }
            max = Math.max(map.get(g[i]), max);
        }
        out.println(ans);
    }
}
