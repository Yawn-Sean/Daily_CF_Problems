
public class cf578a_Leoncn {
    public static void solve() {
        int a = sc.ni();
        int b = sc.ni();
        if(a<b){
            out.println(-1);
            return;
        }
        if(a == b){
            out.println(a);
            return;
        }
        int f = a/b;
        int h = (f - 1)/2;
        int w = (f + 1)/2;
        double ans = Math.min((double) (a-b) /(2*h), (double) (a+b) /(2*w));
        out.println(ans);

    }
}
