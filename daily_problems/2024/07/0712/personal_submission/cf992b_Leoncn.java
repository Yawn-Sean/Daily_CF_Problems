public class cf992b_Leoncn {
    public static void solve() {
        long l = sc.ni();
        long r = sc.ni();
        long x = sc.ni();
        long y = sc.ni();
        if(y%x!=0){
            out.println(0);
            return;
        }
        long f = y/x;
        int ans = 0;
        for (long i =(l+x-1)/x; i*i <= f  && i*i<=y; i++) {
            if(f%i!=0) continue;
            long g = f/i;
            if (g*x<l || g*x>r) continue;
            if(gcd(i,g) == 1){
                ans+=2;
                if(i == g){
                    ans--;
                }
            }
        }
        out.println(ans);
    }
    public static long gcd(long x, long y){
        if(y==0){
            return x;
        }
        return gcd(y,x%y);
    }
}
