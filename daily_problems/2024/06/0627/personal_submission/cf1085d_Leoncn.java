
public class cf1085d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int s = sc.ni();
        int[] cnt = new int[n];
        for (int i = 0; i < n-1; i++) {
            int a = sc.ni() - 1;
            int b = sc.ni() - 1;
            cnt[a] ++;
            cnt[b]++;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if(cnt[i] == 1){
                res ++;
            }
        }
        out.println(2D*s/res);
    }
}
