
public class cf803e_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int k = sc.ni();
        char[] cs = sc.ns().toCharArray();
        Map<Character, int[]> map = new HashMap<>();
        map.put('W',new int[]{1});
        map.put('L',new int[]{-1});
        map.put('D',new int[]{0});
        map.put('?',new int[]{-1, 0, 1});
        int[][] dp = new int[n+1][2*k+1];
        for(int[] d: dp){
            Arrays.fill(d,-2);
        }
        dp[0][k] = 0;
        for (int i = 0; i < n; i++) {
            for(int j: map.get(cs[i])){
                for (int l = 1; l < 2*k; l++) {
                    if (dp[i][l] != -2) {
                        dp[i + 1][l + j] = j;
                    }
                }
            }
        }
        if(dp[n][0]==-2  && dp[n][2*k] == -2){
            out.println("NO");
            return;
        }
        int cur = 0;
        if(dp[n][2*k]!=-2){
            cur = 2*k;
        }
        Map<Integer,Character> status = new HashMap<>();
        status.put(-1, 'L');
        status.put(0, 'D');
        status.put(1, 'W');
        StringBuilder sb = new StringBuilder();
        for (int i = n; i >0 ; i--) {
            sb.append(status.get(dp[i][cur]));
            cur -= dp[i][cur];
        }
        sb.reverse();
        out.println(sb);
    }
}
