int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    Comb::Init();

    int n, k; cin >> n >> k;
    map<int, int> line;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        line[l] += 1;
        line[r + 1] -= 1;
    }

    ll ans = 0;
    ll cur = 0, lst = -2e9;
    for (auto [p, val] : line) {
        if (lst == -2e9) {
            lst = p;
            cur += val;
            continue;
        }
        // cout << "??? " << p - lst << ' ' << cur << '\n';
        if (cur >= k) {
            ans = (ans + 1ll * (p - lst) * Comb::C(cur, k) % mod) % mod;
        }
        lst = p;
        cur += val;
    }

    cout << ans << '\n';

    return 0;
}
