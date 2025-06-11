int main() {
    int n, x;
    cin >> n >> x;
    int l = x, r = x;
    long long ans = 0;
    for (int i = 1; i <= n; i ++) {
        int s, e;
        cin >> s >> e;
        if (s <= l && e >= r) continue;
        if (l <= s && r >= e) {
            l = s;
            r = e;
        } else if (l > e) {
            ans += 1ll * (l - e);
            r = l;
            l = e;
        } else if (r < s) {
            ans += 1ll * (s - r);
            l = r;
            r = s;
        } else if (s <= l) {
            r = e;
        } else {
            l = s;
        }
    }
    cout << ans << endl;
    return 0;
}
