
public class cf1644d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int k = sc.ni();
        int q = sc.ni();
        int[][] g = sc.nmi(q,2);
        boolean[] vis1 = new boolean[n];
        boolean[] vis2 = new boolean[m];
        int cnt1 = 0, cnt2 = 0;
        long ans = 1;
        for (int i = q-1; i >=0; i--) {
            int a = g[i][0] - 1;
            int b = g[i][1] - 1;
            if((vis1[a] && vis2[b]) || (vis1[a]&& cnt1==n) || (vis2[b] && cnt2 == m)){
                continue;
            }
//            if(cnt1 == n && cnt2 == m){
//                continue;
//            }
            if(!vis1[a]){
                vis1[a] = true;
                cnt1++;
            }
 
            if(!vis2[b]){
                vis2[b] = true;
                cnt2++;
            }
            ans = ans * k % 998244353;
;        }
        out.println(ans);
    }
}
