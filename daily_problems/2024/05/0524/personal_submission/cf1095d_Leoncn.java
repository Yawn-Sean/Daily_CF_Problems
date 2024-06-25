
public class cf1095d_Leoncn {
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
        int n = sc.ni();
        int[][] g = new int[n][2];
        for (int i = 0; i < n; i++) {
            int a = sc.ni() - 1;
            int b = sc.ni() - 1;
            g[i] = new int[]{a, b};
        }
        int[] ans = new int[n];
        ans[0] = g[0][0];
        int pre = g[0][1];
        int now = ans[0];
        boolean f = true;
        while (now!= 0){
            int a = g[now][0];
            int b = g[now][1];
            if(a != pre && b != pre){
                f = false;
                break;
            }
            ans[now] = pre;
            now = pre;
            pre = a == pre?b:a;
        }
        if(!f){
            ans = new int[n];
            ans[0] = g[0][1];
            pre = g[0][0];
            now = ans[0];
            while (now!= 0){
                int a = g[now][0];
                int b = g[now][1];
                ans[now] = pre;
                now = pre;
                pre = a == pre?b:a;
            }
        }
        int loc = ans[0];
        while (true ){
            out.print(loc + 1 + " ");
            if(loc == 0){
                break;
            }
            loc = ans[loc];
        }
    }
}
