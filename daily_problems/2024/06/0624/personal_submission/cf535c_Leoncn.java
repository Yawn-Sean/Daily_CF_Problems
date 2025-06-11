public class cf535c_Leoncn {
    public static void solve() {
        int a = sc.ni();
        int b = sc.ni();
        int n = sc.ni();
        for (int i = 0; i < n; i++) {
            long l = sc.ni(), t = sc.ni(), m = sc.ni();
            long left = l, right = t * m + 1;
            while (left < right){
                long  mid = (left + right) / 2;
                if (((a + (l - 1) * b + a + (mid - 1) * b) * (mid - l + 1) / 2 > t * m) || (a + (mid - 1) * b > t)){
                    right = mid ;
                }else{
                    left = mid + 1;
                }

            }
            out.println(left == l ?-1: left-1);

        }
    }

}
