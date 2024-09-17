
public class cf1031d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int k = sc.ni();
        char[][] g = sc.nm(n,n);
        int[][] ans = new int[n+1][n+1];
        for(int[] a: ans){
            Arrays.fill(a, Integer.MAX_VALUE/10);
            ans[0][1] = 0;
        }
        int max = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i+1][j+1] = Math.min(ans[i+1][j], ans[i][j+1]);
                if(g[i][j]!='a'){
                    ans[i+1][j+1]++;
                }
                if(ans[i+1][j+1]<=k){
                    max = Math.max(max, i+j+1);
                }
            }
        }
        Deque<int[]> dq = new ArrayDeque<>();
        StringBuilder res = new StringBuilder();
        if(max == -1){
            res.append(g[0][0]);
            dq.add(new int[]{0,0});
        }else {
            res.append("a".repeat(max));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(ans[i+1][j+1]<=k && max== i + j + 1){
                        dq.add(new int[]{i,j});
                    }
                }
            }
        }
        boolean[][] vis = new boolean[n][n];

        int[][] dirs = new int[][]{{0,1},{1,0}};
        while (dq.size()>0){
            int s = dq.size();
            List<int[]> list = new ArrayList<>();
            int min = 27;
            while (s-->0){
                int[] p = dq.poll();
                for(int[] d: dirs){
                    int x = p[0] + d[0];
                    int y = p[1] + d[1];
                    if(x>=n || y>=n || vis[x][y]) {
                        continue;
                    }
                    vis[x][y] = true;
                    int c = g[x][y]-'a';
                    if(c<min){
                        list = new ArrayList<>();
                        list.add(new int[]{x,y});
                        min = c;
                    }else if(c == min){
                        list.add(new int[]{x,y});
                    }
                }
            }
            dq.addAll(list);
            res.append((char) (min + 'a'));


        }
        out.println(res.deleteCharAt(2*n-1));

    }
}
