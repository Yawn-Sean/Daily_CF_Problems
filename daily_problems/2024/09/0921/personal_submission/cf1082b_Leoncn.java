
public class cf1082b_Leoncn {
    public static void solve() {
        int n = sc.ni();
        char[] cs = sc.ns().toCharArray();
        int loc = 0, cnt = 0;
        int ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            if(cs[i] == 'S'){
                cnt++;
            }
            while (cnt>1){
                if(cs[loc] == 'S'){
                    cnt--;
                }
                loc++;
            }
            if(cs[i] == 'G'){
                sum++;
            }
            ans = Math.max(ans,i-loc+1);
        }
        ans = Math.min(sum, ans);
        out.println(ans);

    }
}
