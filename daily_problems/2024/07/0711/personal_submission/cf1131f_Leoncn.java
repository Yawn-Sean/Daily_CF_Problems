
public class cf1131f_Leoncn {
    public static void solve()
    {
        int n = sc.ni();
        int[][] a = new int[n-1][];
        for(int i = 0;i < n-1;i++){
            a[i] = new int[]{sc.ni(), sc.ni()};
        }

        DisjointSetOfList ds = new DisjointSetOfList(n+1);
        for(int i = 0;i < n-1;i++){
            ds.union(a[i][0], a[i][1]);
        }
        for(int i = ds.root(1);i != -1;i = ds.next[i]){
            out.print(i + " ");
        }
    }

    public static class DisjointSetOfList {
        public int[] upper;
        public int[] next;
        public int[] last;

        public DisjointSetOfList(int n) {
            upper = new int[n];
            Arrays.fill(upper, -1);
            next = new int[n];
            last = new int[n];
            Arrays.fill(next, -1);
            for(int i = 0;i < n;i++){
                last[i] = i;
            }
        }

        public int root(int x) {
            return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
        }

        public boolean equiv(int x, int y) {
            return root(x) == root(y);
        }

        public boolean union(int x, int y) {
            x = root(x);
            y = root(y);
            if (x != y) {
                if (upper[y] < upper[x]) {
                    int d = x;
                    x = y;
                    y = d;
                }
                upper[x] += upper[y];
                upper[y] = x;
                next[last[x]] = y;
                last[x] = last[y];
            }
            return x == y;
        }

        public int count() {
            int ct = 0;
            for (int u : upper)
                if (u < 0)
                    ct++;
            return ct;
        }
    }
}
