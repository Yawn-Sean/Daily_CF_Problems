public class cf689c_Leoncn {
    public static void solve() {
        long m = sc.nl();
        long l = 0, r = (long)1e16;
        long ans = -1;

        while (l < r){
            long mid = l + r >>1;
            long cnt = 0;
            for (long i = 2; i*i*i <= mid;  i++) {
                long f = mid / i/i/i;
                cnt += f;
            }

            if(cnt >= m){
                if(cnt == m){
                    ans = mid;
                }

                r = mid;
            }else {
                l = mid+1;
            }

        }
        out.println(ans);


    }
}
