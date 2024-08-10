/**
 * cf351A
 * x = a.b
 * 向上取整 <=> x - b + 1 when b != 0; x - b when x = 0
 * 向下取整 <=> x - b
 * ans = abs(sum(x) - (sum(b) + k)), k为向上取整的个数
 * 需要根据的取值来求min(ans), k 属于 [max(0, n - cnt0), min(n, 2 * n - cnt0)]
 *  */ 
void solve() {
    int n;
    cin >> n;
    int tot = 0, cnt0 = 0, ans = inf<int>;
    rep (i, 0, 2 * n) {
        string s;
        int b;
        cin >> s;
        b = stoi(s.substr(s.find('.') + 1));
        tot += b; 
        cnt0 += !b;
    }
    rb (k, max(0, n - cnt0), min(2 * n - cnt0, n)) {
        ans = min(ans, abs(tot - k * 1000));
    }
    cout << ans / 1000 << '.' << ans % 1000/100 << ans % 100/10 << ans % 10;
}
