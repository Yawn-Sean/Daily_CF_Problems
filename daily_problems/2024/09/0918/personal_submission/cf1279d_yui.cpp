#define int i64

void solve() {
    int n;
    cin >> n;

    vec2<int> a(n);
    map<int, int> rec;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (auto& x : a[i]) {
            cin >> x;
            rec[x]++;
        }
    }

    Z ans = 0;
    for (auto& v : a) {
        for (auto& i : v) {
            ans += (Z)rec[i] / (Z)v.size();
        }
    }

    cout << ans / (Z)(n * n) << '\n';
}
