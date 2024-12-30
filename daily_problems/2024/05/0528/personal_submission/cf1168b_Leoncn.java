
public class cf1168b_Leoncn {
    public static void solve(){
        char[] cs = sc.ns().toCharArray();
        int n = cs.length;
        int pre = -1;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <=10 ; j++) {
                if(i-2*j <0) {
                    break;
                }
                if(cs[i] == cs[i-j] && cs[i] == cs[i-2*j]){
                    pre = Math.max(i-2*j, pre);
                }
            }
            ans += pre + 1;
        }
        out.println(ans);
    }
}
