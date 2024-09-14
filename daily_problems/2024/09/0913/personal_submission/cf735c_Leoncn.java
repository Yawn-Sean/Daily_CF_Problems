public class cf735c_Leoncn {
    public static void solve() {
        long n = sc.nl();
        long d1 = 2, d2 = 1;
        long ans = 0;
        while (d1<=n){
            long tem = d1;
            d1 = d2 + d1;
            d2 = tem;
            ans++;
        }
        out.println(ans);
    }
}
