public class Main {
    
    int[] a, b;

    void solve() {
        int n = ni();
        a = new int[n]; b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        dfs(0, n - 1);
        for (int v : a) {
            print(v).print(' ');
        }
        writeln();
    }

    void dfs(int l, int r) {
        if (l + 1 >= r) {
            return;
        }
        int j = l;
        for (int i = l; i <= r; i += 2) {
            b[j++] = a[i];
        }
        int m = j - 1;
        for (int i = l + 1; i <= r; i += 2) {
            b[j++] = a[i];
        }
        System.arraycopy(b, l, a, l, r - l + 1);
        dfs(l, m);
        dfs(m + 1, r);
    }

    public static void main(String[] args) {
        new Main() {{for (int i = 1; i > 0; i--) solve();}}.flush();
    }
}
