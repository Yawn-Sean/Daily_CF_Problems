
public class cf761e_Leoncn {
    static ArrayList<Integer>[] g;
    static int[][] dirs;
    static String[] ans;
    private static void solve() {
        int n = sc.ni();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < n-1; i++) {
            int a = sc.ni() - 1;
            int b = sc.ni() - 1;
            g[a].add(b);
            g[b].add(a);
        }
        for (int i = 0; i < n; i++) {
            if(g[i].size()>4){
                out.println("NO");
                return;
            }
        }
        out.println("YES");
        ans = new String[n];
        dirs = new int[][]{{-1,0},{1,0},{0,-1},{0,1}};
        dfs(0, -1, new int[]{-1,-1}, 0,0,0);
        ans[0] = "0 0";
        for(String s: ans){
            out.println(s);
        }
    }

    private static void dfs(int c, int p, int[] parDir, int d, int lastX, int lastY){

        boolean[] v = new boolean[4];
        for(int w: g[c]){
            if(w != p){
                int nextX = 0, nextY = 0;
                int[] curDir = new int[]{};
                for (int i = 0; i < 4; i++) {
                    if(v[i] || (parDir[0] +dirs[i][0] == 0 &&  parDir[1] + dirs[i][1] == 0)){
                        continue;
                    }
                    v[i] = true;
                    curDir = dirs[i];
                    nextX = lastX + dirs[i][0] *( 1<<(29-d));
                    nextY = lastY + dirs[i][1] *( 1<<(29-d));
                    break;
                }
                ans[w] = nextX+ " " + nextY;
                dfs(w, c, curDir, d+1, nextX, nextY);
            }
        }
    }

}
