public class cf1019a_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);


    public static void main(String[] args) {
        int t = 1;
        while (t-->0){
            solve();
        }
        out.close();

    }

    public static void solve(){
        int n = sc.ni();
        int m = sc.ni();
        long ans = Long.MAX_VALUE;
        int[] cnt = new int[m];
        int[][] g = new int[n][2];
        for (int i = 0; i < n; i++) {
            int a = sc.ni() - 1;
            int v = sc.ni();
            g[i] = new int[]{a,v};
            cnt[a]++;
        }
        Arrays.sort(g, (a,b)->a[1]-b[1]);

        for (int i = 0; i <n; i++) {
            long sum = 0;
            int[] w = new int[m];
            boolean[] v = new boolean[n];
            for (int j = 0; j < n; j++) {
                int a = g[j][0];
                if(a==0) {
                    v[j] = true;
                    continue;
                }
                if(cnt[a]-w[a]>i){
                    sum += g[j][1];
                    w[0]--;
                    w[a]++;
                    v[j] = true;
                }
            }
            int loc = 0;
            while (cnt[0]-w[0]<=i){
                for (int j = loc; j < n; j++) {
                     if(!v[j]){
                         w[0]--;
                         sum += g[j][1];
                         loc = j+1;
                         break;
                     }
                }
            }
            ans = Math.min(ans, sum);
        }
        out.println(ans);
    }

}
