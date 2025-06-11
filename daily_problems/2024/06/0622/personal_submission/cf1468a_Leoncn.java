
public class cf1468a_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] g = sc.na(n);
        int[] pre = new int[n];
        Deque<Integer> dq = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            while (dq.size()>0 && g[dq.peekFirst()]<=g[i]){
                dq.pollFirst();
            }
            if(dq.size() == 0){
                pre[i] = -1;
            }else {
                pre[i] = dq.peekFirst();
            }
            dq.addFirst(i);
        }
        int[][] arr = new int[n][2];
        for (int i = 0; i < n; i++) {
            arr[i][0] = g[i];
            arr[i][1] = i;
        }
        Arrays.sort(arr, (a, b)->a[0] - b[0]);

        FenwickMax f = new FenwickMax(n+1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int loc = arr[i][1];
            int res = Math.max(0,f.query(1, loc))+1;
            if(pre[loc] != -1){
                res = Math.max(res, Math.max(0,f.query(1,pre[loc])) + 2);
            }
            f.updata(loc+1, res);
            ans = Math.max(res, ans);
        }
        out.println(ans);
    }
    /**
     * 最大值
     * */
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
