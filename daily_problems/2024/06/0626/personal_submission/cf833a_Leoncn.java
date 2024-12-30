public class cf833a_Leoncn {
    
    public static void solve() {
        long a = sc.ni();
        long b = sc.ni();
        long s = a * b;
        long l = 1, r = (int)1e6+1;
        while (l <r){
            long m = (l + r) / 2;
            if ( m * m * m >s) {
                r = m ;
            }else {
                l = m + 1;
            }
        }
        l --;
        out.println(l * l *l == s && a%l == 0 && b%l == 0 ?"Yes":"No");
    }
}
