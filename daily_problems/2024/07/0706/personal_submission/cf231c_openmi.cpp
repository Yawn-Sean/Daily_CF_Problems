void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    int x;
    rep (i, 0, n) {
        cin >> x;
        mp[x]++;
    }
    int m = mp.size();
    vi v, cnt;
    for (auto& [ke, ct]: mp) {
        v.push_back(ke);
        cnt.push_back(ct);
    }
    mp.clear();
    // j处使用了多少 cnt[j]
    vi used(m);
    // taken个数变成了v[i]
    int cost_k = k, taken = 0, ans = 0, ans_v = v.back(), tm, l = m - 2;
    br (r, m - 1, 0) {
        l = min(r - 1, l);
        while (l >= 0 and v[r] - v[l] <= cost_k) {
            tm = min(cost_k / (v[r] - v[l]), cnt[l] - used[l]);
            used[l] += tm;
            taken += tm;
            cost_k -= tm * (v[r] - v[l]);
            if (used[l] == cnt[l]) --l;
            else break;
        }
        if (cnt[r] + taken == ans) {
            ans_v = v[r];
        } else if (cnt[r] + taken > ans) {
            ans_v = v[r];
            ans = cnt[r] + taken;
        }
        if (r) cost_k += (v[r] - v[r-1]) * taken, taken -= used[r-1];
    }
    cout << ans << ' ' << ans_v << nl;
}
