
public class cf1579e2_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] g = sc.na(n);
        int[] sorted = new int[n];
        System.arraycopy(g,0, sorted, 0, n);
        Arrays.sort(sorted);
        Fenwick tree = new Fenwick(n+1);
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int loc = Arrays.binarySearch(sorted, g[i])+1;
            int c = tree.pre(loc-1);
            int f =  i - tree.pre(loc);
            ans += Math.min(f, c);
            tree.add(loc);
        }
        out.println(ans);

    }
    static class Fenwick {
        int[] tree;

        Fenwick(int n) {
            tree = new int[n + 1];
        }

        void add(int at) {
            for (at++; at < tree.length; at += at & -at) {
                tree[at]++;
            }
        }

        int pre(int at) {
            int s = 0;
            for (at++; at > 0; at -= at & -at) {
                s += tree[at];
            }
            return s;
        }

        int pre(int l, int r) {
            return pre(r) - pre(l - 1);
        }

    }
}
