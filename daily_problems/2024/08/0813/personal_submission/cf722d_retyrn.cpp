int n;

bool check(vector<int>& a, set<int>& S, int mx) {
    for (auto x : a) {
        while (x > 0) {
            if (x > mx or S.count(x)) {
                x >>= 1;
                continue;
            }
            S.insert(x);
            break;
        }
        if (!x) return false;
    }
    return true;
}

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    int l = 1, r = *max_element(all(a));
    while (l < r) {
        auto mid = (l + r) >> 1;
        set<int> S;
        if (check(a, S, mid)) r = mid;
        else l = mid + 1;
    }
    set<int> S;
    check(a, S, l);
    for (auto x : S) {
        cout << x << ' ';
    }
    cout << endl;
}