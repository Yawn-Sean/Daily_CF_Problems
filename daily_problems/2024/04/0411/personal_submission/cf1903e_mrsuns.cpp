void Solve(int TIME) {

    int n;cin >> n;
    vc<set<int>> st(2);
    int sx, sy;cin >> sx >> sy;
    for (int i = 1;i <= n;i++) {
        int x, y;cin >> x >> y;
        st[(x + y) % 2].insert(i);
    }
    int pr = (sx + sy) % 2;
    int po;
    int p = 0;
    if (st[pr].size() >= st[pr ^ 1].size()) cout << "First" << endl;
    else cout << "Second" << endl, p = 1;
    for (int i = 1;i <= n;i++) {
        if ((i + p) & 1) {
            if (st[pr ^ 1 ^ p].size()) cout << *st[pr ^ 1 ^ p].begin() << endl, st[pr ^ 1 ^ p].erase(st[pr ^ 1 ^ p].begin());
            else cout << *st[pr ^ p].begin() << endl, st[pr ^ p].erase(st[pr ^ p].begin());;
        }
        else {
            cin >> po;
            if (st[pr ^ 1 ^ p].count(po)) st[pr ^ 1].erase(po);
            else st[pr ^ p].erase(po);
        }
    }
}



signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);

    PreWork();

    int T = 1;
    cin >> T;

    int TIME = 0;
    while (T--) {
        Solve(++TIME);
    }

    return 0;
}
