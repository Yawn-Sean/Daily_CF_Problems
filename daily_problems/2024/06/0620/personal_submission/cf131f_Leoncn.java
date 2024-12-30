public class cf131f_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int k = sc.ni();
        char[][] g = new char[n][m];
        for (int i = 0; i < n; i++) {
            g[i] = sc.ns().toCharArray();
        }
        int[][] cnt = new int[n][m];
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                if(g[i][j] == '0') continue;
                if(g[i-1][j] == '1' && g[i+1][j]=='1' && g[i][j-1] =='1' && g[i][j+1] == '1'){
                    cnt[i][j]++;
                }
            }
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int[] c = new int[m];
            for (int j = i+2; j < n; j++) {
                for (int l = 0; l < m; l++) {
                    c[l] += cnt[j-1][l];
                }
                int loc = 1;
                int cur = 0;
                for (int l = 1; l < m; l++) {
                    cur += c[l-1];
                    while (cur>=k){
                        cur-=c[loc++];
                    }
                    ans+=loc-1;
                }
            }
        }
        out.println(ans);
 
    }
}
