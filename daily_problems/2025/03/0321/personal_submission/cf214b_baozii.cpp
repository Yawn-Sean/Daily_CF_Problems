int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
    multiset<int> a;
    int c = 0;
    rep(i, 0, n) {
        int x;
        cin >> x;
        a.insert(-x);
        c += x;
    }
    if (*a.rbegin() != 0) {
        cout << -1;
        return 0;
    }
    c %= 3;
    vvi b(3);
    for (auto x : a) b[(-x) % 3].pb(-x);
    rep(i, 0, 3) sort(ALL(b[i]));
    if (c == 1) {
        if (!b[1].empty()) {
            a.erase(a.find(-b[1][0]));
        } else if (b[2].size() >= 2) {
            a.erase(a.find(-b[2][0]));
            a.erase(a.find(-b[2][1]));
        } else {
            cout << -1;
            return 0;
        }
    } else if (c == 2) {
        if (!b[2].empty()) {
            a.erase(a.find(-b[2][0]));
        } else if (b[1].size() >= 2) {
            a.erase(a.find(-b[1][0]));
            a.erase(a.find(-b[1][1]));
        } else {
            cout << -1;
            return 0;
        }
    }
    if (*a.begin() == 0) cout << 0;
    else for (auto x : a) cout << -x;
}
