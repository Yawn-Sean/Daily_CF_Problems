
public class cf792d_Leoncn {
    public static void solve() {
        long max = sc.nl();
        int q = sc.ni();
        while (q-->0){
            long n = sc.nl();
            char[] cs = sc.ns().toCharArray();
            for(char c: cs){
                long m = n & -n;
                if(c == 'L'){
                    if(m>1){
                        n -= m/2;
                    }
                }else if(c == 'R'){
                    if(m>1){
                        n += m/2;
                    }
                }else {
                    if(m *2< max){
                        n -= m;
                        n |= m*2;
                    }
                }
            }
            out.println(n);
        }
    }
}
