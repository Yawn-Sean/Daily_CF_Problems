const int N = 2e5 + 5;

int n, m, a[N], t[N], r[N], top, ans[N];
multiset<int> S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) {
        int t0, r0;
        cin >> t0 >> r0;
        while(top && r[top] <= r0) --top;
        ++top; t[top] = t0; r[top] = r0;
    }
    rep(i, 1, r[1]) S.insert(a[i]);
    rep(i, r[1] + 1, n) ans[i] = a[i];
    int u = 1;
    per(i, r[1], 1) {
        while(u < top && i <= r[u + 1]) ++u;
        if(t[u] == 1) {ans[i] = *--S.end(); S.erase(--S.end());}
        else {ans[i] = *S.begin(); S.erase(S.begin());}
    }
    rep(i, 1, n) cout << ans[i] << " \n"[i == n];
    return 0;
}
