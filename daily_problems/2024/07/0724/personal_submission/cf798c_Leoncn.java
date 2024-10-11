
public class cf798c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] g = sc.na(n);
        int c = g[0];
        for (int i = 1; i < n; i++) {
            c = gcd(c, g[i]);
        }
        out.println("YES");
        if(c>1){
            out.println("0");
            return;
        }
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if((g[i]&1) == 1){
                cnt++;
            }else {
                ans += cnt/2 + (cnt & 1)*2;
                cnt = 0;
            }
        }
        ans += cnt/2 + (cnt & 1)*2;
        out.println(ans);
    }
    public static int gcd(int x, int y){
        if(y==0){
            return x;
        }
        return gcd(y,x%y);
    }
}
