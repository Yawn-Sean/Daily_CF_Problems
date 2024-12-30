public class cf960c_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    public static void solve() {
        int x = sc.ni();
        int d = sc.ni();

        long c = 1L;
        int cnt = 0;
        long now = 1L;

        while (c*2-1<=x){
            c*=2;
            cnt++;
        }
        int sum = 0;
        StringBuilder sb = new StringBuilder();
        while (x>1){
            while (x> c-1){
                x -= c-1;
                sum+= cnt;
                for (int i = 0; i < cnt; i++) {
                    sb.append(now).append(" ");
                }
                now += d+1;
            }
            c/=2;
            cnt--;
        }

        for (int i = 0; i < x; i++) {
            sb.append(now).append(" ");
            now += d+1;
        }
        out.println(sum + x);
        out.println(sb);



    }

}
