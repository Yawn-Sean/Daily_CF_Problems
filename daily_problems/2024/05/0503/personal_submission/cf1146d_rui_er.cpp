const ll N = 3e5 + 5;

ll m, a, b, vis[N];

ll dfs(ll u, ll L) {
    if(vis[u]) return 0;
    ll ans = 1;
    vis[u] = 1;
    if(u + a <= L) ans += dfs(u + a, L);
    if(u - b >= 0) ans += dfs(u - b, L);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> m >> a >> b;
    ll k = min(a + b - 1, m);
    ll now = dfs(0, 0), ans = now;
    rep(i, 1, k) {
        if(i - a >= 0 && vis[i - a]) now += dfs(i, i);
        ans += now;
    }
    if(k < m) {
        ll g = __gcd(a, b), p = 0;
        rep(i, k + 1, m) {
            if(i % g == 0) {
                p = i;
                break;
            }
            ans += i / g + 1;
        }
        ll d = m / g * g - 1;
        ans += (d - p + 1) + (m / g - 1 + p / g) * (m / g - p / g) / 2 * g;
        rep(i, d + 1, m) ans += i / g + 1;
    }
    cout << ans << endl;
    return 0;
}
