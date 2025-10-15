int main()
{
    ll n; cin >> n;
    vector<int> a(n + 1), res(n + 1, -1);
    iota(a.begin(), a.end(), 0);
    for(int i = n; i >= 0; i --) {
        if(res[i] != -1) continue;
        int cnt = log2(i) + 1;
        int k = (1 << cnt) - 1;
        res[i] = k ^ i, res[k ^ i] = i;
    }
    cout << n * (n + 1) << endl;
    for(int i = 0; i <= n; i ++) cout << res[i] << " \n"[i == n];
    // for(int i = 0; i <= n; i ++) cout << a[i] << " \n"[i == n];
    // vector<int> ans;
    // int mx = 0;
    // do {
    //     int t = 0;
    //     for(int i = 0; i <= n; i ++) {
    //         t += (i ^ a[i]);
    //     }
    //     if(t == n * (n + 1)) {
    //         for(int i = 0; i <= n; i ++) cout << a[i] << " \n"[i == n];
    //     }
    //     if(t > mx) {
    //         mx = t;
    //         ans = a;
    //     }
    // }while(next_permutation(a.begin(), a.end()));
    // cout << mx << endl;
    // //for(int i = 0; i <= n; i ++) cout << ans[i] << " \n"[i == n];
    // for(int i = 0; i <= n; i ++) {
    //     cout << (n ^ i) << " \n"[i == n];
    // }
    return 0;
}
