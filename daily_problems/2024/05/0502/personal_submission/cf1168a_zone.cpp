void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    int l = 0, r = m;
 
    auto check = [&](int x, int lst) -> bool {
        for (int i = lst != 0; i < n; i ++ ) {
            // cerr << i << ' ' << lst << ' ' << (a[i] + x) % m << ' ' << a[i] << endl;
            int v = a[i];
            if (v >= lst) {
                if ((v + x) % m < lst || (v + x) % m >= v) lst = v;
            } else if (v + x < lst) {
                return false;
            }
        }
        return true;
    };
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid, 0)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}   
 
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    solve();
    return 0;
}
