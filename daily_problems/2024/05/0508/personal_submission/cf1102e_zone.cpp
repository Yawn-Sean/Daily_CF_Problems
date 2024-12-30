void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    unordered_map<int, PII> p;
    for (int i = 0; i < n; i ++ ) {
        if (p.count(a[i]) == 0) p[a[i]] = {i, i};
        else p[a[i]].second = i;
    }
    vector<PII> pos, fil;
    for (auto [x, v]: p) pos.push_back(v);
    sort(pos.begin(), pos.end());
    int ans = 1;
    fil.push_back(pos[0]);
    for (auto [l, r]: pos) {
        auto [l_, r_] = fil.back();
        if (l > r_) { 
            ans = (1LL * 2 * ans) % MOD2;
            fil.emplace_back(l, r);
        } else {
            l_ = min(l_, l);
            r_ = max(r_, r);
            fil.back() = {l_, r_};
        }
    }
    cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    solve();
    return 0;
}
