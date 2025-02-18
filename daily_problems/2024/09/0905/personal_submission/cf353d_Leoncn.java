
public class cf353d_Leoncn {
    public static void solve() {
        int ans = 0;
        int cur = 0;
        for(char c: sc.ns().toCharArray()){
            if(c == 'M'){
                cur++;
            }else if(cur>0){
                ans = Math.max(ans+1, cur);
            }
        }
        out.println(ans);
    }

}
