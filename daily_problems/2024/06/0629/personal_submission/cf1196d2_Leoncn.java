public class cf1196d2_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int k = sc.ni();
        char[] cs = sc.ns().toCharArray();
        char[] tar = {'R','G','B'};
        int ans = n+1;
        for (int i = 0; i < 3; i++) {
            int f = i;
            int[] pre = new int[n+1];
            for (int j = 0; j < n; j++) {
                pre[j+1] = pre[j];
                if(cs[j]!= tar[f]){
                    pre[j+1]++;
                }
                f = (f+1)%3;
                if(j+1>=k){
                    ans = Math.min(ans, pre[j+1] - pre[j+1-k]);
                }
            }
        }
        out.println(ans);
    }
}
