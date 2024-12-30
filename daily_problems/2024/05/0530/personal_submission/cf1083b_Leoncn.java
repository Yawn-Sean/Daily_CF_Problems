

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
    int k = sc.ni();
    char[] cs = sc.ns().toCharArray();
    char[] tar = sc.ns().toCharArray();
    long ans = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        cur = cur *2 + (tar[i] - cs[i]);
        cur = Math.min(cur, k);
        ans += Math.min(cur+1, k);
    }
    out.println(ans);
}