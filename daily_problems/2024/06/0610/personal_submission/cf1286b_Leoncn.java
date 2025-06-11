

public class cf1286b_Leoncn {
    static ArrayList<Integer>[] g;
    static int[] cnt;
    static boolean result;
    public static void solve() {
        int n = sc.ni();
        cnt = new int[n];
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        int r = 0;
        for (int i = 0; i < n; i++) {
            int a = sc.ni() - 1;
            cnt[i] = sc.ni();
            if(a==-1){
                r = i;
            }else {
                g[a].add(i);
            }
        }
        List<Integer> ans = dfs(r);
        if(result){
            out.println("NO");
            return;
        }
        out.println("YES");

        int[] f = new int[n];
        for (int i = 0; i < n; i++) {
            f[ans.get(i)] = i+1;
        }
        for (int i = 0; i < n; i++) {
            out.print(f[i] + " ");
        }
    }
    private static List<Integer> dfs(int c){
        List<Integer> res = new ArrayList<>();
        for(int w: g[c]){
            res.addAll(dfs(w));
        }
        if(res.size()<cnt[c]){
            result = true;
            return res;
        }
        res.add(cnt[c], c);
        return res;
    }
}
