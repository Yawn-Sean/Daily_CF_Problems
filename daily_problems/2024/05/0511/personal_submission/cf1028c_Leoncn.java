public class cf1028c_Leoncn {
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
        int MAX = Integer.MAX_VALUE;
        int MIN = Integer.MIN_VALUE;
        int[][] g = sc.nmi(n,4);
        int minRX = MAX/2;
        int minRY = MAX/2;
        int maxLX = MIN/2;
        int maxLY = MIN/2;
        int[][] pre = new int[n+1][4];
        for (int i = 0; i <=n; i++) {
            pre[i] =  new int[]{MAX,MAX,MIN,MIN};
        }
        pre[0][0] = maxLX;
        pre[0][1] = maxLY;
        pre[0][2] = minRX;
        pre[0][3] = minRY;
        for (int i = 0; i < n; i++) {
            maxLX = Math.max(g[i][0], maxLX);
            maxLY = Math.max(g[i][1], maxLY);
            minRX = Math.min(g[i][2], minRX);
            minRY = Math.min(g[i][3], minRY);
            if(maxLX>minRX || maxLY>minRY){
                continue;
            }
            pre[i+1][0] = maxLX;
            pre[i+1][1] = maxLY;
            pre[i+1][2] = minRX;
            pre[i+1][3] = minRY;
        }
        minRX = MAX/2;
        minRY = MAX/2;
        maxLX = MIN/2;
        maxLY = MIN/2;
        int[][] suf = new int[n+1][4];
        for (int i = 0; i <=n; i++) {
            suf[i] =  new int[]{MAX,MAX,MIN,MIN};
        }
        suf[n][0] = maxLX;
        suf[n][1] = maxLY;
        suf[n][2] = minRX;
        suf[n][3] = minRY;
        for (int i = n-1; i >=0 ; i--) {
            maxLX = Math.max(g[i][0], maxLX);
            maxLY = Math.max(g[i][1], maxLY);
            minRX = Math.min(g[i][2], minRX);
            minRY = Math.min(g[i][3], minRY);
            if(maxLX>minRX || maxLY>minRY){
                continue;
            }
            suf[i][0] = maxLX;
            suf[i][1] = maxLY;
            suf[i][2] = minRX;
            suf[i][3] = minRY;
        }

        for (int i = 0; i < n; i++) {
            int a = Math.max(pre[i][0], suf[i+1][0]);
            int b = Math.max(pre[i][1], suf[i+1][1]);
            int c = Math.min(pre[i][2], suf[i+1][2]);
            int d = Math.min(pre[i][3], suf[i+1][3]);
            if(a>c || b>d) {
                continue;
            }
            out.println(a + " " + b);
            break;
        }
    }    
}
