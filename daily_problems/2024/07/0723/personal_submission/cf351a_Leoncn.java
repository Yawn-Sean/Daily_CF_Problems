
public class cf351a_Leoncn {
    public static void solve() {
        int n = sc.ni();
        double tot = 0;
        int cnt = 0;
        for (int i = 0; i < 2*n; i++) {
            double d = sc.nd();
            d = d - Math.floor(d);
            if(d == 0){
                cnt++;
            }
            tot += d;
        }
        int f = Math.max(0, n - cnt);
        int to = Math.min(2*n - cnt, n);
        double ans = Double.MAX_VALUE;
        for (int i = f; i <=to ; i++) {
            ans = Math.min(ans,Math.abs(i- tot));
        }
        out.println(String.format("%.3f", ans));
    }
}
