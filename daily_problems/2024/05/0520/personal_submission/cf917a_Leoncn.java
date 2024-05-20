
public class cf917a_Leoncn {
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
        char[] cs = sc.ns().toCharArray();
        int n = cs.length;
        int ans  = 0;
        for (int i = 0; i < n; i++) {
            int c = 0, now = 0;
            for (int j = i; j <n ; j++) {
                if(cs[j] == '('){
                    now++;
                }else if(cs[j] == ')'){
                    now--;
                }else if(cs[j] == '?'){
                    c++;
                    now --;

                }
                if(now<0){
                    if(c>0){
                        c--;
                        now+=2;
                    }
                }
                if(now<0){
                    break;
                }
                if(now == 0){
                    ans ++;
                }
            }
        }
        out.println(ans);
    }    
}
