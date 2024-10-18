
public class cf1023d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int q = sc.ni();
        int[] g = sc.na(n);

        int[] l = new int[q+1];
        int[] r = new int[q+1];
        Arrays.fill(l, -1);
        Arrays.fill(r, -1);
        int pre = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if(g[i]== q){
                cnt ++;
            }
        }
        for (int i = 0; i < n; i++) {
            if(g[i] == 0 && cnt == 0){
                g[i] = q;
                l[q] = i;
                r[q] = i;
                cnt++;
            }else if(g[i] == 0){
                g[i] = pre;
            }else {
                pre = g[i];
            }
        }
        FenwickMin fenwickMin = new FenwickMin(n);
        for (int i = 0; i < n; i++) {
            if(l[g[i]] == -1){
                l[g[i]] = i;
            }
            fenwickMin.updata(i+1,g[i]);
        }
        if(l[q] == -1){
            out.println("NO");
            return;
        }
        for (int i = n-1; i >=0 ; i--) {
            if(r[g[i]] == -1){
                r[g[i]] = i;
            }
        }
        for (int i = q; i >=1; i--) {
            if(l[i] == -1) continue;
            if(fenwickMin.query(l[i]+1, r[i]+1)<i){
                out.println("NO");
                return;
            }
        }
        out.println("YES");
        for(int c: g){
            out.print(c +" ");
        }

    }
    /**
     * 最小值
     * */
    public static class FenwickMin {
        int[] tree;
        int[] arr;
        int n;
        FenwickMin(int _n) {
            n = _n;
            tree = new int[n + 1];
            arr = new int[n+1];
            Arrays.fill(arr, Integer.MAX_VALUE/10);
            Arrays.fill(tree, Integer.MAX_VALUE/10);
        }
        private int lowbit(int x) {
            return x & (-x);
        }

        void updata(int x, int k) {
            int lx = x;
            arr[x] = k;
            while(x < n) {
                tree[x] = Math.min(tree[x], arr[lx]);
                x += lowbit(x);
            }
        }

        int query(int x, int y) {
            int ans = Integer.MAX_VALUE/10;
            while(y >= x){
                ans = Math.min(arr[y], ans);
                y --;
                for(; y - lowbit(y) >= x; y -= lowbit(y)) ans = Math.min(tree[y], ans);
            }
            return ans;
        }
    }
}
