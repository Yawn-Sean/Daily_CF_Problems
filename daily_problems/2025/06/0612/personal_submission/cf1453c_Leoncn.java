
public class cf1453c_Leoncn {
        public static void solve() {
        int n = sc.ni();
        char[][] a = sc.nm(n,n);
        int[] ans = new int[10];

        int[] down = new int[10];
        int[][] left = new int[10][n];
        int[] top = new int[10];
        Arrays.fill(down, -1);
        Arrays.fill(top, -1);

        int[] le = new int[10];
        int[] ri = new int[10];
        int[][] to = new int[10][n];

        for(int[] w: left){
            Arrays.fill(w, -1);
        }
        for(int[] w: to){
            Arrays.fill(w, -1);
        }
        Arrays.fill(le, -1);
        Arrays.fill(ri, -1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int c = a[i][j] -'0';
                down[c] = i;
                if(top[c] == -1){
                    top[c] = i;
                }
                if(left[c][i] == -1){
                    left[c][i] = j;
                }

                ri[c] = Math.max(j, ri[c]);
                if(le[c] == -1){
                    le[c] = j;
                }else{
                    le[c] = Math.min(le[c], j);
                }
                if(to[c][j] == -1){
                    to[c][j] = i;
                }else {
                    to[c][j] = Math.min(to[c][j], i);
                }

            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int c = a[i][j] -'0';
                //平行横坐标
                int res = Math.max(i-top[c], down[c]-i) * Math.max(j, n-j-1);
                res = Math.max(res, (j-left[c][i]) * Math.max(i, n-i-1));
                //平行纵坐标
                res = Math.max(res, Math.max(j-le[c], ri[c]-j) * Math.max(i, n-i-1));
                res = Math.max(res, (i-to[c][j]) * Math.max(j, n-j-1));
                ans[c] = Math.max(res, ans[c]);
            }
        }

        for (int i = 0; i < 10; i++) {
            out.print(ans[i] + " ");
        }
        out.println(" ");
    }
}
