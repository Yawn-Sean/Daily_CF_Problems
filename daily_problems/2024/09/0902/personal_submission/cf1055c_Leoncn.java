public class cf1055c_Leoncn {
    public static void solve() {
        int la = sc.ni(), ra = sc.ni(), ta = sc.ni();
        int lb = sc.ni(), rb = sc.ni(), tb = sc.ni();
        int a = ra - la + 1;
        int b = rb - lb + 1;
        int x = la - lb;
        int g = gcd(ta, tb);
        x = (x % g+ g)%g;
        out.println(Math.max(0, Math.max(Math.min(x + a, b) - x, Math.min(x - g + a, b))));
    }
    public static int gcd(int x, int y){
        if(y==0){
            return x;
        }
        return gcd(y,x%y);
    }

}
