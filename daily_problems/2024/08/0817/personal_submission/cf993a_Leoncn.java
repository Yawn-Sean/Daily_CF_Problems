
public class cf993a_Leoncn {
    public static void solve() {
        int[] s1 = sc.na(8);
        int[] s2 = sc.na(8);
        if(check(s2,s1)){
            out.println("YES");
        }else {
            for (int i = 0; i < 8; i+=2) {
                s1[i] += s1[i+1];
                s1[i+1] = s1[i] - s1[i+1]*2;
                s2[i] += s2[i+1];
                s2[i+1] = s2[i] - s2[i+1]*2;
            }
            if(check(s1, s2)){
                out.println("YES");
            }else {
                out.println("NO");
            }
        }
    }
    private static boolean check(int[] s1, int[] s2){
        int xl = 100, xr = -100, yl = 100, yr = -100;
        for (int i = 0; i < 8; i++) {
            if((i&1)==1){
                yl = Math.min(yl, s2[i]);
                yr = Math.max(yr, s2[i]);
            }else {
                xl = Math.min(xl, s2[i]);
                xr = Math.max(xr, s2[i]);
            }
        }
        for (int i = 0; i < 8; i+=2) {
            if(s1[i]>=xl && s1[i]<=xr && s1[i+1]>=yl && s1[i+1]<=yr){
                return true;
            }
        }
        return s1[0] + s1[4] >= xl*2 && s1[0] + s1[4] <= xr *2 && s1[1] + s1[5] >= yl*2 && s1[1] + s1[5] <= yr*2;
    }

}
