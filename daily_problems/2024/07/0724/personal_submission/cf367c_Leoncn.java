
public class cf367c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int[] g = new int[m];
        for (int i = 0; i < m; i++) {
            int x = sc.ni();
            g[i] = sc.ni();
        }
        Arrays.sort(g);
        long ans = 0;
        for (int i = 0; i < m; i++) {
            long d = i;
            if(d *(d + 1)/2 + d %2 *d /2 + 1 > n ){
                break;
            }
            ans += g[m-i-1];
        }
        out.println(ans);

    }

}
