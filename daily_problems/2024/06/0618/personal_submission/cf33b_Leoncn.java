
public class cf33b_Leoncn {
    public static void solve() {
        char[] cs = sc.ns().toCharArray();
        char[] to = sc.ns().toCharArray();
        if(cs.length!=to.length){
            out.print(-1);
            return;
        }
        int n = cs.length;
        int[][] dis = new int[26][26];
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                dis[i][j] = Integer.MAX_VALUE/2;
            }
            dis[i][i] = 0;
        }
        int q = sc.ni();
        for (int i = 0; i < q; i++) {
            int a = sc.nc()-'a';
            int b = sc.nc() - 'a';
            int t = sc.ni();
            dis[a][b] = Math.min(t, dis[a][b]);
        }
        for (int k = 0; k < 26; k++) {
            for (int x = 0; x < 26; x++) {
                for (int y = 0; y < 26; y++) {
                    dis[x][y] = Math.min(dis[x][y], dis[x][k] + dis[k][y]);
                }
            }
        }
        int ans = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if(cs[i] == to[i]) {
                sb.append(cs[i]);
                continue;
            }
            int min = Integer.MAX_VALUE/2;
            int r = 0;
            for (int j = 0; j < 26; j++) {
                int s = dis[cs[i]-'a'][j] + dis[to[i]-'a'][j];
                if(s<min){
                    min = s;
                    r = j;
                }
            }
            if(min == Integer.MAX_VALUE/2){
                out.print(-1);
                return;
            }
            sb.append((char) ('a'+r));
            ans += min;
        }
        out.println(ans);
        out.println(sb);
    }
}
