// https://codeforces.com/contest/1270/submission/258761871

/* 我永远喜欢爱莉希雅♪ */
int n, k;
pair<int, int> ask(vector<int> id) {
    idle++;
    assert(ranges::is_sorted(id) && id.size() == k);
    cout << "?";
    for (int i: id) cout << ' ' << i + 1;
    cout << endl;
    ranges::sort(id, [&](int i, int j) { return p[i] < p[j]; });
    int x = id[m - 1], y = p[x];
    cout << "ret: " << x << ' ' << y << endl;
    return {x, y};
}
 
void bingo(int ans) {
    cout << "exp: " << m << ", got: " << ans << endl;
    cout << "! " << ans << endl;
    assert(ans == m);
    assert(idle <= n);
}
 
void elysia() {
    cin >> n >> k;
    vector<int> q(k);
    iota(itr(q), 0);
    auto [i0, x] = ask(q);
    q[i0] = k;
    ranges::sort(q);
    auto [i1, y] = ask(q);
    int ans = 1;
    for (int i: q) {
        if (i != i1) {
            vector<int> h = q;
            *ranges::find(h, i) = i0;
            ranges::sort(h);
            if (ask(h).first == i1) {
                ans += x < y;
            } else {
                ans += x > y;
            }
        }
    }
    bingo(ans);
}
