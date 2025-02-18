
public class cf641c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int q = sc.ni();
        int a = 0, b = 0;
        int ta = 1;
        while (q-->0){
            int type = sc.ni();
            if( type == 1){
                int move = (sc.ni() + n)%n;
                a += move;
                b += move;
                ta = (ta + move)&1;
            }else {
                if(ta==1){
                    a = a+1;
                    b = b-1;
                }else {
                    a = a-1;
                    b = b+1;
                }
                ta^=1;
            }
            a %= n;
            b %= n;

        }
        int[] ans = new int[n];
        for (int i = 0; i < n; i+=2) {
            ans[ (i + a)%n] = i+1;
        }
        for (int i = 1; i < n; i+=2) {
            ans[ (i + b)%n] = i+1;
        }
        for (int i = 0; i < n; i++) {
            out.print(ans[i] + " ");
        }
//        1 2 3 4 5 6 7 8
//        8 1 2 3 4 5 6 7
//        1 8 3 2 5 4 7 6
//        4 7 6 1 8 3 2 5
//        7 4 1 6 3 8 5 2

    }
}
