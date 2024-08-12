
public class cf1329b_Leoncn {
    public static void solve() {
        long d = sc.nl();
        long m = sc.nl();
        long tem = 1;
        long ans = 1;

        while (tem<=d){
            ans = ans *( Math.min(tem, d - tem + 1) + 1) % m;
            tem *=2 ;
        }
        out.println((ans - 1 + m)%m );
    }

}
