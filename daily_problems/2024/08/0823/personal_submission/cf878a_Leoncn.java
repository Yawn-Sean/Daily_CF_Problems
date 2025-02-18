
public class cf878a_Leoncn {
    public static void solve(){
        int n = sc.ni();
        int r1 = 0;
        int r2 = (1<<10) - 1;
        for (int i = 0; i < n; i++) {
            char c = sc.nc();
            int g = sc.ni();
            if(c == '&'){
                r1 &= g;
                r2 &= g;
            }else if(c == '|'){
                r1 |= g;
                r2 |= g;
            }else {
                r1 ^= g;
                r2 ^= g;
            }
        }
        int h = 0, k = 0, s = (1<<10)-1;
        for (int i = 0; i <= 9; i++) {
            int a = (r1>>i) & 1;
            int b = (r2>>i) & 1;
            if(a==1 && b == 1){
                k |= (1<<i);
            }else if(a == 0  && b == 1){

            }else if(a == 1 && b == 0){
                h |= (1<<i);
            }else {
                s ^= (1<<i);
            }
        }
        out.println(3);
        out.println('^' + " " + h);
        out.println('|' + " " + k);
        out.println('&' + " " + s);
    }

}
