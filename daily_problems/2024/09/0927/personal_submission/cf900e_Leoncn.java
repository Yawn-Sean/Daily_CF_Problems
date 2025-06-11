public class cf900e_Leoncn {
    private static void solve() {
        int n = sc.ni();
        char[] cs = sc.ns().toCharArray();
        int m = sc.ni();

        // 长度
        int[] cntA = new int[n+1];
        int[] cntB = new int[n+1];
        int[] pre = new int[n+1];
        for (int i = 0; i < n; i++) {
            pre[i+1] = pre[i];
            if(cs[i] == '?'){
                pre[i+1]++;
            }
        }
        for (int i = n-1; i >=0 ; i--) {
            cntA[i] = cs[i]!='b'?(cntB[i+1]+ 1):0;
            cntB[i] =  cs[i]!='a'?(cntA[i+1] + 1):0;
        }
        int[] dp = new int[n+1];
        int[] change = new int[n+1];
        for (int i = 0; i < n; i++) {
            if(dp[i]>dp[i+1] || (dp[i] == dp[i+1] && change[i]< change[i+1])){
                dp[i+1] = dp[i];
                change[i+1] = change[i];
            }
            if(cntA[i]>=m){
                int nv = dp[i] + 1 ;
                int nc = change[i] + pre[i+m] - pre[i];
                if(nv>dp[i+m] || (nv == dp[i+m] && nc<change[i+m])){
                    dp[i+m] = nv;
                    change[i+m] = nc;
                }
            }
        }
        out.println(change[n]);
    }
}
