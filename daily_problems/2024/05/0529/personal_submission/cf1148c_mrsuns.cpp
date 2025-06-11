void Solve() {
    int n;cin >> n;
    vector<int> a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    vector<int> b = a;
    vector<int> p(n + 1);for (int i = 1;i <= n;i++) p[a[i]] = i;
    vector<array<int, 2>> res;
    if (a[1] != 1) {
        int v = p[1];
        if (v <= n / 2) {
            res.push_back({ v,n });
            res.push_back({ 1,n });
            res.push_back({ v,n });
        }
        else {
            res.push_back({ v,1 });
        }
        swap(a[1], a[v]);
        swap(p[a[1]], p[a[v]]);
    }
    if (a[n] != n) {
        int v = p[n];
        if (v <= n / 2) {
            res.push_back({ v,n });
        }
        else {
            res.push_back({ v,1 });
            res.push_back({ 1,n });
            res.push_back({ v,1 });
        }
        swap(a[n], a[v]);
        swap(p[a[n]], p[a[v]]);
    }
 
    for (int i = 2;i < n;i++) {
        if (a[i] != i) {
            int u = i, v = p[i];
            if (u <= n / 2) {
                res.push_back({ u,n });
                if (v <= n / 2) {
                    res.push_back({ v,n });
                    res.push_back({ u,n });
                }
                else {
                    res.push_back({ v,1 });
                    res.push_back({ 1,n });
                    res.push_back({ u,n });
                    res.push_back({ v,1 });
                }
            }
            else {
                res.push_back({ u,1 });
                if (v > n / 2) {
                    res.push_back({ v,1 });
                    res.push_back({ u,1 });
                }
                else {
                    res.push_back({ v,n });
                    res.push_back({ 1,n });
                    res.push_back({ u,1 });
                    res.push_back({ v,n });
                }
            }
            swap(a[u], a[v]);
            swap(p[a[u]], p[a[v]]);
        }
    }
    cout << res.size() << endl;
    for (auto [l, r] : res) {
        cout << l << ' ' << r << endl;
        //swap(b[l], b[r]);
    }
    //debugsq(b);
}
