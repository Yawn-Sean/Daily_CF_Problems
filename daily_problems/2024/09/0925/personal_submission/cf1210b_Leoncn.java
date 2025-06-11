
public class cf1210b_Leoncn {
    public static void solve(){
        int n = sc.ni();
        long[] a = sc.nal(n);
        long[] b = sc.nal(n);
        Map<Long,Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.merge(a[i],1, Integer::sum);
        }
        long ans = 0;
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; i++) {
            if(!vis[i] && map.get(a[i])>1){
                vis[i] = true;
                ans += b[i];
                for (int j = 0; j < n; j++) {
                    if(!vis[j] && (a[j] | a[i]) == a[i]){
                        vis[j] = true;
                        ans += b[j];
                    }
                }
            }
        }

        out.println(ans);


    }
}
