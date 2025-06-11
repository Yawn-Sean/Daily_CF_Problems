import java.io.PrintWriter;
import java.util.Arrays;

public class cf799c_Leoncn {
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
        int c = sc.ni();
        int d = sc.ni();
        FenwickMax max1 = new FenwickMax(100003);
        FenwickMax max2 = new FenwickMax(100003);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int b = sc.ni();
            int p = sc.ni();
            char s  = sc.nc();
            if(s == 'C'){
                if(p>c) continue;
                ans = Math.max(max1.query(1, c-p) + b, ans);
                ans = Math.max(max2.query(1,d)+b, ans);
                max1.updata(p,b);
            }else {
                if(p>d) continue;
                ans = Math.max(max1.query(1, c) + b, ans);
                ans = Math.max(max2.query(1,d-p)+b, ans);
                max2.updata(p,b);
            }
        }
        out.println(ans);
    }

    public static class FenwickMax {
        int[] tree;
        int[] arr;
        int n;
        FenwickMax(int _n) {
            n = _n;
            tree = new int[n + 1];
            arr = new int[n+1];
            Arrays.fill(arr, Integer.MIN_VALUE/10);
            Arrays.fill(tree, Integer.MIN_VALUE/10);
        }
        private int lowbit(int x) {
            return x & (-x);
        }

        void updata(int x, int k) {
            int lx = x;
            arr[x] = k;
            while(x < n) {
                tree[x] = Math.max(tree[x], arr[lx]);
                x += lowbit(x);
            }
        }

        int query(int x, int y) {
            int ans = Integer.MIN_VALUE/10;
            while(y >= x){
                ans = Math.max(arr[y], ans);
                y --;
                for(; y - lowbit(y) >= x; y -= lowbit(y)) ans = Math.max(tree[y], ans);
            }
            return ans;
        }
    }
}
