public class cf309a_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int l = sc.ni();
        int t = sc.ni();
        int[] g = sc.na(n);

        t *=2;
        int d = t%l;
        double ans = 1.0*n *(n-1)*(t/l);
        int[] nums = new int[2*n];
        for (int i = 0; i < n; i++) {
            nums[i] = g[i];
        }
        for (int i = n; i < 2*n; i++) {
            nums[i] = g[i-n] + l;
        }
        int loc = 0;
        for (int i = n; i < 2*n; i++) {
            while (nums[i]- nums[loc]>d){
                loc++;
            }
            ans += i-loc;
        }
        out.println(ans/4);
    }
}
