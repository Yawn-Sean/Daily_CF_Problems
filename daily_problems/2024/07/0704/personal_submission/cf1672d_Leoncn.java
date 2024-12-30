public class cf1672d_Leoncn {
    public static void solve() {

        int n = sc.ni();
        int[] g = sc.na(n);
        int[] tar = sc.na(n);
        int[] cnt = new int[n+1];
        int loc = n-1;
        int i = n-1;
        while (i>=0){
            if(g[loc] == tar[i]){
                i--;
                while (i>=0 && tar[i] == tar[i+1]){
                    cnt[tar[i--]]++;
                }
            }else if(cnt[g[loc]]>0){
                cnt[g[loc]]--;
            }else {
                out.println("NO");
                return;
            }
            loc --;
        }
        out.println("YES");
    }
}
