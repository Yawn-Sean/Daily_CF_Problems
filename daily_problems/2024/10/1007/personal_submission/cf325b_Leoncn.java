
public class cf325b_Leoncn {
    public static void solve() {
        long n = sc.nl();
        boolean f = false;

        for (int i = 0; i < 60; i++) {
            long l = 0, r = (long)2e9;
            long v = 1L<<i;
            while (l<r){
                long mid = (r -l >>1) + l;
                if (  mid == 0 || (v - 1) < (n - mid * (mid - 1) / 2)/mid){
                    l = mid + 1;
                }else {
                    r = mid;
                }
            }
            if ((l * (l - 1) / 2 + r * (v - 1) == n) && (l % 2 == 1)){
                out.println(l * v);
                f = true;
            }
        }
        if(!f){
            out.println(-1);
        }


    }
}
