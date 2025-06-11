ll ab(ll x){
    if(x < 0)return -x;
    else return x;
}
int main(void){
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> a(m);
    vector<vector<ll>> b(n + 1);
    vector<ll> cnt(n + 1, 0);
    ll ans = 0, dif = 0;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        if(i && a[i] != a[i - 1]){
            b[a[i]].push_back(a[i - 1]);
            ans += ab(a[i] - a[i - 1]);
            b[a[i - 1]].push_back(a[i]);
        }
    }
    
    for(int i = 1; i <= n; i++){
        sort(b[i].begin(), b[i].end());
        if(!b[i].size())continue;
        ll temp = b[i][(b[i].size() - 1) / 2], t_dif = 0;
        for(auto it : b[i]){
            t_dif += ab(i - it) - ab(temp - it);
        }
        dif = max(dif, t_dif);
    }
    cout << (ans - dif);
}
