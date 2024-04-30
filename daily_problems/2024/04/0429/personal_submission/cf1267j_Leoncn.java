public class cf1267j_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = sc.ni();
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    public static void solve() {
        int n = sc.ni();
        int[] g =  sc.na(n);
        Map<Integer,Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.merge(g[i],1,Integer::sum);
        }
        List<Integer> list = new ArrayList<>();
        int min = Integer.MAX_VALUE;
        for(int v: map.values()){
            list.add(v);
            min = Math.min(min, v);
        }
        int ans = n+1;
        out:for (int i = 1; i <= min; i++) {
            int c = 0;
            for(int v:list){
                int cur = (v - 1) / (i + 1) + 1;
                c += cur;
                if(i*cur>v){
                    continue out;
                }
            }
            ans = Math.min(c,ans );
        }
        out.println(ans);

    }
}
