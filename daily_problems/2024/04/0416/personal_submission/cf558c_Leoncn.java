public class cf558c_Leoncn {
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
        int[] g = sc.na(n);
        int max = 0;
        for (int i = 0; i < n; i++) {
            if(g[i]>max){
                max = g[i];
            }
        }
        int c = 0;
        int[] dp = new int[100001];
        int[] cnt = new int[100001];

        int pre = -1;
        for(int k= max; k>=1;k>>=1){

            int x = k;
            int h = c;
            cnt[x]++;
            dp[x]+=h;
            h++;
            x*=2;
            if(pre != x){
                while (x<=max){
                    //set.add(x);
                    cnt[x]++;
                    dp[x]+=h;
                    h++;
                    x*=2;
                }
            }
            pre =k;
            c++;
        }

        int ans = Integer.MAX_VALUE;
        int w = 1;
        for (int i = n-1; i >=0; i--) {
            if(max == g[i] && w==1){
                w = 0;
                continue;
            }
            c = 0;
            pre = -1;
            for(int k= g[i]; k>=1;k>>=1){
                int x = k;
                int h = c;
                cnt[x]++;
                dp[x]+=h;
                h++;
                x*=2;
                if(pre != x){
                    while (x<=max){
                        //set.add(x);
                        cnt[x]++;
                        dp[x]+=h;
                        h++;
                        x*=2;
                    }
                }
                pre =k;
                c++;
            }
        }
        for (int i = 1; i <=100000; i++) {
            if(cnt[i] == n){
                ans = Math.min(dp[i],ans);
            }
        }
        out.println(ans);

    }
}