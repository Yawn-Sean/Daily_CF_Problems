public class cf1578h_Leoncn {
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
        Deque<Integer> dq = new ArrayDeque<>();

        for (int i = n-1; i >=0 ; i--) {
            if(cs[i] == ')'){
                dq.offerFirst(-1);
            }else if(cs[i] == '>'){
                dq.offerFirst(-2);
                i--;
            }else  {
                int c = 0;
                while (dq.size()>0 && dq.peekFirst()!=-1){
                    c += dq.pollFirst();
                }
                dq.pollFirst();
                if (dq.size() >0&& dq.peekFirst() == -2){
                    dq.pollFirst();
                    c = Math.max(c+1, dq.pollFirst());

                }
                dq.offerFirst(c);
            }
        }
        out.println(dq.pollFirst());

    }
}
