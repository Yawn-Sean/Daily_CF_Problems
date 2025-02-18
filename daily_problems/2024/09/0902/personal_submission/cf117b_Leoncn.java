public class cf117b_Leoncn {
    public static void solve() {
        int a = sc.ni();
        int b = sc.ni();
        int mod = sc.ni();
        int x = (int)(1e9) %mod;
        int v = 0;
        for (int i = 0; i <=a && i<mod; i++) {
            if(v>b){
                out.println(1 + " " + String.format("%09d", i));
                return;
            }
            v = (v + mod - x)%mod;
        }
        out.println(2);
    }
}
