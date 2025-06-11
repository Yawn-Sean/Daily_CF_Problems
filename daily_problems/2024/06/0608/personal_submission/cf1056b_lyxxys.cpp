using ll = long long;
const int N = 1011, mod = 1000001, inf = 1e9;
ll f[N];
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i) f[i*i%m] += n/m;
    for (ll i = m*(n/m)+1; i <= n; ++ i) ++ f[i*i%m];

    ll res = 0;
    for (int i = 0; i < m; ++ i) res += f[i] * f[i ? m-i : 0];
    cout << res << "\n";
}
