
public class cf756a_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = sc.ni() - 1;
        }
        int[] b = sc.na(n);
        boolean[] vis = new boolean[n];
        int cnt = 0, c = 0;
        for (int i = 0; i < n; i++) {
            if(!vis[i]){
                int tem = i;
                while (!vis[tem]){
                    vis[tem] = true;
                    tem = p[tem];
                }
                cnt ++;
            }
            if(b[i] == 1){
                c++;
            }
        }
        int ans = (cnt>1?cnt:0) +((c+1)&1);
        out.println(ans);
    }

}
