
public class cf1177b_Leoncn {
    public static void solve() {
        long n = sc.nl();
        long s = 0;
        long now = 1;
        long cnt = 9;
        while (s + now * cnt<n){
            s += now * cnt;
            now ++;
            cnt *=10;
        }
        long left = n- s;
        long f = (long) ((left-1)/now + Math.pow(10, now-1));
        int g = (int)((left-1)%now);
        out.println((f+"").charAt(g));


    }
}
