void solve() {
    ll n, m;
    cin >> n >> m;
    vector<int> p(n);
    int l = 0, r = n - 1, v = 1;
    while (l <= r) {
        ll mid = 1LL << (r - l - 1);
        if (m > mid) p[r--] = v ++, m -= mid;
        else p[l ++ ] = v ++;
    }
    printv(p, ' ', false);
}

// 打表
// void solve() {
//     int n, ans = 0, mn = inf<int> ;
//     cin >> n;
//     vector<int> a(n), p(n);
//     rep (i, 0, n) p[i] = i + 1;
//     unordered_map<int, vvi> mp;
//     int mx = 0;
//     do {
//         ans = 0;
//         for (int i = 0; i < n; ++i) {
//             mn = inf<int>;
//             for (int j = i; j < n; ++j) {
//                 mn = min(mn, p[j]);
//                 // cout << mn << endl;
//                 ans += mn;
//             }
//         }
//         chmax(mx, ans);
//         mp[ans].push_back(p);
//     } while (next_permutation(all(p)));
//     cout << mx << nl;
//     for (auto& p: mp[mx]) {
//         printv(p);
//     }
// }
