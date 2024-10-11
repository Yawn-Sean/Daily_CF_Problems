public class cf425b_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int k = sc.ni();
        int[][] g = sc.nmi(n,m);
        int ans = k + 1;
        if(m <=k){
            for (int msk = 0; msk < 1 << (m - 1); msk ++) {
                int res = 0;
                for (int i = 0; i < n; i ++) {
                    int cnt = 0;
                    for (int j = 0; j < m; j ++)
                        cnt += g[i][j] == (msk >> j & 1)?1:0;
                    res += Math.min(cnt, m - cnt);
                }
                ans = Math.min(ans, res);
            }
        }else {
            for (int i = 0; i < m; i++) {
                int res = 0;
                for (int j = 0; j < m; j++) {
                    int cnt = 0;
                    for (int l = 0; l < n; l++) {
                        if(g[l][j] == g[l][i]){
                            cnt++;
                        }
                    }
                    res += Math.min(cnt, n-cnt);
                }
                ans = Math.min(ans, res);
            }
        }
        out.println(ans<=k?ans:-1);
    }

}
