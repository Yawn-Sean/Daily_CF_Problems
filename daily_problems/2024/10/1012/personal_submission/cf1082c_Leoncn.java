public class cf1082c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        List<Integer>[] g = new ArrayList[m];
        for (int i = 0; i < m; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            int a = sc.ni() - 1;
            int b = sc.ni();
            g[a].add(b);
        }
        int[] sum = new int[n];
        for (int i = 0; i < m; i++) {
            Collections.sort(g[i], (a,b)->b-a);
            int s = 0;
            int loc = 0;
            for(int w :g[i]){
                s += w;
                if(s>=0){
                    sum[loc++] += s;
                }else {
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n ; i++) {
            ans = Math.max(sum[i], ans);
        }
        out.println(ans);
    }
}
