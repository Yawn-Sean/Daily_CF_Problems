public class cf281b_Leoncn {
    public static void solve() {

        long x = sc.ni();
        long y = sc.ni();
        long n = sc.ni();
        long ansX = 0;
        long ansY = 1;
        long difX = x;
        long difY = y;
        for (int i = 1; i <=n ; i++) {
            long d = x * i /y;
            for (long j = d; j < d+2 ; j++) {
                long temDifX = Math.abs( x * i -  y * j), temDifY = y *i;
                if(temDifX * difY < difX * temDifY){
                    ansX = j;
                    ansY = i;
                    difX = temDifX;
                    difY = temDifY;
                }
            }
        }
        out.println( ansX + "/" + ansY);
    }

}
