public class cf226b_Leoncn {
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
        int[] g = sc.na(n);
        Arrays.sort(g);
        long[] pre = new long[n+1];
        for (int i = 0; i < n; i++) {
            pre[i+1] = pre[i] + g[i];
        }
        int q = sc.ni();
        int max = (int)1e5+1;
        long[] cnt = new long[max];
        for (int i = 0; i < q; i++) {
            int a = sc.ni();
            if(cnt[a]==0){
                long s = 0;
                long c = a;
                long w = 1;
                long j = n-2;
                while (j>=0){
                    s += w*(pre[(int)j+1] - pre[(int)(Math.max(j-c+1,0))]);
                    j-=c;
                    c*=a;
                    w++;
                }
                cnt[a] = s;
            }
            out.println(cnt[a]);
        }
    }
}
