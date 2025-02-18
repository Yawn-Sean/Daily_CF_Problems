
public class cf1227d2_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[][] arr = new int[n][2];
        int[] g = sc.na(n);
        for (int i = 0; i < n; i++) {
            arr[i][0] = g[i];
            arr[i][1] = i;
        }
        Arrays.sort(arr, (a,b)->{
            if(a[0] == b[0]){
                return a[1]- b[1];
            }
            return b[0] - a[0];
        });
        int m = sc.ni();
        int[][] q = new int[m][3];
        for (int i = 0; i < m; i++) {
            q[i][0] = sc.ni();
            q[i][1] = sc.ni() - 1;
            q[i][2] = i;
        }
        Arrays.sort(q, (a,b)->a[0]-b[0]);
        int[] ans = new int[m];
        BIT bit = new BIT(n+10);
        int len = 0;
        for (int i = 0; i < m; i++) {
            int[] a = q[i];
            while (len<a[0]){
                int ind = arr[len][1];
                bit.update(ind+1, 1);
                len++;
            }
            int ind = a[1];
            ans[a[2]] = bit.getKth(ind);
        }
        for(int a: ans){
            out.println(g[a-1]+ " ");
        }
    }
    static class BIT {
        int n;int[]tree;
        public BIT(int N) {
            n=N;
            tree=new int[N+1];
        }
        void update(int i, int val) {
            for (i++; i<=n; i+=i&-i)
                tree[i]+=val;
        }
        int read(int i) {
            int sum=0;
            for (i++; i>0; i-=i&-i)
                sum+=tree[i];
            return sum;
        }
        // query sum of [l, r] inclusive
        int query(int l, int r) {
            return read(r)-read(l-1);
        }
        // if the BIT is a freq array, returns the index of the
        // kth item (0-indexed), or n if there are <= k items.
        int getKth(int k) {
            if (k<0)
                return -1;
            int i=0;
            for (int pw=Integer.highestOneBit(n); pw>0; pw>>=1)
                if (i+pw<=n&&tree[i+pw]<=k)
                    k-=tree[i+=pw];
            return i;
        }
    }
}
