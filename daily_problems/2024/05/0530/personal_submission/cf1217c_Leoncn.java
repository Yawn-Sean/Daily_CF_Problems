
public class cf1217c_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = sc.ni();
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    public static void solve() {
        String s = sc.ns();
        char[] cs = s.toCharArray();
        int n =  cs.length;
        int[] pre = new int[n+1];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            pre[i+1] = pre[i] + (cs[i]-'0');
            int min = Math.max(0, i-29);
            int c = 0;
            for (int j = i; j >=min; j--) {
                c |= (cs[j]-'0')<<(i-j);
                if(c == i-j+1) {
                    ans++;
                }
            }
            if(i+1-c>=0  && i+1-c<min && pre[min+1] - pre[i+1-c] == 0){
                ans++;
            }
        }
        out.println(ans);
    }
}
