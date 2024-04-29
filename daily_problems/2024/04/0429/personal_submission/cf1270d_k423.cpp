// https://codeforces.com/contest/1270/submission/258761871

/* 我永远喜欢爱莉希雅♪ */
int n, k;
pair<int, int> ask(vector<int> id) {
    cout << "?";
    for (int i: id) cout << ' ' << i + 1;
    cout << endl;
    int x, y;
    cin >> x >> y;
    return {x - 1, y};
}
 
void bingo(int ans) {
    cout << "! " << ans << endl;
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
