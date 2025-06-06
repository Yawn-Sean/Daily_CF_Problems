void solve(){
    int n, m, i, j, a, b;
    cin >> n >> m >> i >> j >> a >> b;

    auto find = [&](int x, int y)->int{
        if (abs(x-i)%a || abs(y-j)%b) return inf_int;
        int k1 = abs(x-i)/a, k2 = abs(y-j)/b;
        if ((k1+k2)%2) return inf_int;
        return max(k1, k2);
    };
    int ans = inf_int;
    for (auto u : {1, n}){
        for (auto v : {1, m}){
            fmin(ans, find(u, v));
        }
    }
    if ((i==1||i==n) && (j==1||j==m)) cout << 0 << "\n";
    else if (a >= n || b >= m || ans == inf_int) cout << "Poor Inna and pony!";
    else cout << ans << "\n";
}
