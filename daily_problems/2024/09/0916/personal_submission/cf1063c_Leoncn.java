
public class cf1063c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int l = 0;
        int r = (int) 1e9;
        int res = q(r);
        for (int i = 0; i < n-1; i++) {
            int mid = l + r  >> 1;
            if(q(mid) == res){
                r = mid;
            }else {
                l = mid;
            }
        }
        int ans = l + r >> 1;
        out.println(ans + " " + (ans + 1)  + " " +  (ans + 1) + " " + ans);

    }
    private static int q(int f){
        out.println(f + " " + f);
        out.flush();
        String s = sc.ns();
        return s.equals("white")?0:1;
    }
}
