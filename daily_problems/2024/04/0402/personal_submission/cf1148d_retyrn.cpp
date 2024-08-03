int n;
using ai3 = array<int, 3>;
//-----------------------function-----------------------

void solve() {
    cin >> n;
    // 分为两类 一类是递增 一类递减
    vector<ai3> A, B;
    for (int i = 1; i <= n; i ++) {
        int x, y;
        cin >> x >> y;
        if (x > y) {
            B.push_back({x, y, i});
        }
        if (x < y) {
            A.push_back({x, y, i});
        }
    }
    if (sz(A) >= sz(B)) {
        // 按照第一位倒序
        cout << sz(A) << endl;
        sort(all(A), greater<>());
        for (auto [x, y, id] : A) {
            cout << id << ' ';
        }
        cout << endl;
    }
    else {
        // 按照第一位顺序
        cout << sz(B) << endl;
        sort(all(B));
        for (auto [x, y, id] : B) {
            cout << id << ' ';
        }
        cout << endl;
    }
    
}
int main() {
    FAST;
    // Tsolve();
    solve();

    return 0;
}