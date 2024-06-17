
public class cf811d_Leoncn {
    static int[] dr = new int[]{1, 0, -1, 0};
    static int[] dc = new int[]{0, 1, 0, -1};
    static char[] D = "DRUL".toCharArray();
    static int[] move(int k)
    {
        out.println(D[k]);
        out.flush();
        return new int[]{sc.ni()-1, sc.ni()-1};
    }
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        char[][] g = new char[n][m];
        for (int i = 0; i < n; i++) {
            g[i] = sc.ns().toCharArray();
        }
        int fr = -1, fc = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(g[i][j] == 'F'){
                    fr = i;
                    fc = j;
                    break;
                }
            }
        }

        int[][] dis = d(g, fr, fc);
        int[] cur = null;
        if(m >= 2 && dis[0][0] > dis[0][1]){
            cur = move(1);
            if(cur[1] == 1){
            }else{
                char c = D[1]; D[1] = D[3]; D[3] = c;
            }
            while(dis[cur[0]][cur[1]] > 0){
                if(n >= 2 && dis[cur[0]][cur[1]] > dis[cur[0]+1][cur[1]]){
                    cur = move(0);
                    if(cur[0] == 1){
                    }else{
                        char c = D[0]; D[0] = D[2]; D[2] = c;
                    }
                    break;
                }
                cur = move(1);
            }
        }else{
            cur = move(0);
            if(cur[0] == 1){
            }else{
                char c = D[0]; D[0] = D[2]; D[2] = c;
            }
            while(dis[cur[0]][cur[1]]> 0){
                if(m >= 2 && dis[cur[0]][cur[1]] > dis[cur[0]][cur[1]+1]){
                    cur = move(1);
                    if(cur[1] == 1){
                    }else{
                        char c = D[1]; D[1] = D[3]; D[3] = c;
                    }
                    break;
                }
                cur = move(0);
            }
        }

        while(dis[cur[0]][cur[1]] > 0){
            for(int k = 0;k < 4;k++){
                int nr = cur[0] + dr[k], nc = cur[1] + dc[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && dis[cur[0]][cur[1]] > dis[nr][nc]){
                    cur = move(k);
                    break;
                }
            }
        }

    }

    private static int[][] d(char[][] g, int fr, int fc){
        int[] dr = { 1, 0, -1, 0 };
        int[] dc = { 0, 1, 0, -1 };
        int n = g.length;
        if(n == 0)return new int[0][0];
        int m = g[0].length;
        int l = dr.length;
        int[][] d = new int[n][m];
        int I = 999999999;
        for(int i = 0;i < n;i++) {
            Arrays.fill(d[i], 999999999);
        }

        int B = Integer.numberOfTrailingZeros(Integer.highestOneBit(m))+1;
        Queue<Integer> q = new ArrayDeque<Integer>();
        q.add(fr<<B|fc);
        d[fr][fc] = 0;

        while(!q.isEmpty()){
            int cur = q.poll();
            int r = cur>>>B, c = cur&(1<<B)-1;
            for(int k = 0;k < l;k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] != '*' && d[nr][nc] == I) { // fix
                    d[nr][nc] = d[r][c] + 1;
                    q.add(nr<<B|nc);
                }
            }
        }
        return d;
    }

}
