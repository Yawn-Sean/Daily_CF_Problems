public class cf960d_Leoncn {
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
        int q = sc.ni();
        long[] shifts = new long[61];
        while (q-->0){
            int t = sc.ni();
            long x = sc.nl();


            if(t == 1){
                long k = sc.nl();
                int idx = Long.toBinaryString(x).length();
                shifts[idx] += k;
                shifts[idx] =  (shifts[idx] % ((1L<<idx - 1))+ (1L<<idx - 1))%(1L<<idx -1);

            }else if(t == 2){
                long k = sc.nl();
                int idx = Long.toBinaryString(x).length();
                for (int i = idx; i<61; i++) {
                    shifts[i] += k;
                    k = ((k )%(1L<<i -1) + (1L<<i -1))%((1L<<i -1));
                    shifts[i] =  (shifts[i] % ((1L<<i - 1))+ (1L<<i - 1))%(1L<<i -1);
                    k *= 2;
                }
            }else {
                int idx = Long.toBinaryString(x).length();
                long pos = (x - (1L << idx - 1) + shifts[idx]) % (1L << idx - 1);
                StringBuilder sb = new StringBuilder();
                for (int i = idx; i >0 ; i--) {
                    sb.append( (1L << i - 1) + ((pos - shifts[i]) % (1L << i - 1) + (1L<<i -1)) % (1L<<i -1)).append(" ");
                    pos/=2;
                }
                out.println(sb);
            }
        }


    }

}
