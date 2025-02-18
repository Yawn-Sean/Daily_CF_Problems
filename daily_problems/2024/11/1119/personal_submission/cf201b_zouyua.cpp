void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int> (m + 1));
    ll a = 0, bx = 0, by = 0, c = 0;
    for(int i = 2; i < 4 * n; i += 4) {
        for(int j = 2; j < 4 * m; j += 4) {
            ll x; cin >> x;
            a += x;
            bx -= 2 * i * x;
            by -= 2 * j * x;
            c += (i * i + j * j) * x;
        }
    }
    ll resx = 0, resy = 0;
    if(a == 0) {
        resx = 0, resy = 0;
    } else {
        int z = -bx / (2 * a) / 4;
        int zz = z + 1;
        z *= 4, zz *= 4;
        if(abs(a * z * z + bx * z) >= abs(a * zz * zz + bx * zz)) resx = z;
        else resx = zz;
        z = -by / (2 * a) / 4;
        zz = z + 1;
        z *= 4, zz *= 4;
        if(abs(a * z * z + by * z) >= abs(a * zz *zz + by * zz)) resy = z;
        else resy = zz;        
    }

    ll ans = a * (resx * resx + resy * resy) + bx * resx + by * resy + c;
    cout << ans << endl;
    cout << resx / 4 << ' ' << resy / 4 << endl;
    
}
