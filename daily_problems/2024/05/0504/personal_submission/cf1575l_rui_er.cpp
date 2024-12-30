const int N = 2e5 + 5;

int n, m, a[N], f[N], len;
tuple<int, int> b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) if(i - a[i] >= 0) b[++m] = make_tuple(i - a[i], a[i]);
    sort(b + 1, b + 1 + m);
    rep(i, 1, m) {
        int val = get<1>(b[i]);
        if(!len || f[len] < val) f[++len] = val;
        else *lower_bound(f + 1, f + 1 + len, val) = val;
    }
    cout << len << endl;
    return 0;
}
