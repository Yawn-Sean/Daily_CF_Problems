public class cf1200d_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    public static void solve() {
        int n = sc.ni();
        int k = sc.ni();
        char[][] g = sc.nm(n,n);
        int[][] dif = new int[n+2][n+2];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int max = -1;
            int min = n;
            for (int j = 0; j < n; j++) {
                if(g[i][j] == 'B'){
                    max = Math.max(max, j);
                    min = Math.min(min, j);
                }
            }
            if(min>max){
                ans++;
            }else {
                if(min + k - 1>=max){
                    int xl = Math.max(0, i - k + 1) + 1;
                    int xr = i + 1;
                    int yl = Math.max(0, max-k+1) + 1 ;
                    int yr = min + 1;
                    dif[xl][yl] ++;
                    dif[xr+1][yl] --;
                    dif[xl][yr+1] --;
                    dif[xr+1][yr+1] ++;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            int max = -1;
            int min = n;
            for (int i = 0; i < n; i++) {
                if(g[i][j] == 'B'){
                    max = Math.max(max, i);
                    min = Math.min(min, i);
                }
            }
            if(min>max){
                ans++;
            }else {
                if(min + k - 1>=max){
                    int xl = Math.max(0, max - k + 1) + 1;
                    int xr = min + 1;
                    int yl = Math.max(0, j-k+1) + 1;
                    int yr = j + 1;
                    dif[xl][yl] ++;
                    dif[xr+1][yl] --;
                    dif[xl][yr+1] --;
                    dif[xr+1][yr+1] ++;
                }
            }
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dif[i+1][j+1] += dif[i + 1][j] + dif[i][j + 1] - dif[i][j];
                max = Math.max(dif[i+1][j+1], max);
            }
        }
        out.println(ans + max);

    }
}
