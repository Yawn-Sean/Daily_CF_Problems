public class cf314b_Leoncn {
    
    public static void solve(){
        int b = sc.ni();
        int d = sc.ni();
        String a = sc.ns();
        String c = sc.ns();
        int n = a.length();
        int m = c.length();
        char[] cs = a.toCharArray();
        char[] tar = c.toCharArray();
        int[][] dp = new int[m][2];
        for (int i = 0; i < m; i++) {
            int loc = 0;
            int st = i;
            int cnt = 0;
            while (loc<n){
                if(tar[st] == cs[loc]){
                    st++;
                }
                if(st == m){
                    st = 0;
                    cnt++;
                }
                loc++;
            }
            dp[i] = new int[]{cnt, st};
        }
        int pre = 0;
        long sum = 0;
        for (int i = 0; i < b; i++) {
            sum += dp[pre][0];
            pre = dp[pre][1];
        }
        out.println(sum/d );

    }
}
