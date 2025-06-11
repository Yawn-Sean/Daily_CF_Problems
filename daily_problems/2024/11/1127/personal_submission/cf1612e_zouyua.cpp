int main()
{
    int n; cin >> n;
    vector<int> m(n + 1), k(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> m[i] >> k[i];
    }
    int qwgx = 0, c = 1;
    vector<int> resv;
    for(int cnt = 1; cnt <= min(n, 20); cnt ++) {
        map<int, int> vt;
        for(int i = 1; i <= n; i ++) vt[m[i]] += min(k[i], cnt);
        vector<array<int, 2>> gx;
        for(auto &[x, y] : vt) gx.pb({y, x});
        sort(gx.begin(), gx.end(), [](auto &a,auto &b){
            return a[0] > b[0];
        });
        int sumf = 0;
        for(int i = 0; i < min(cnt, (int)gx.size()); i ++) sumf += gx[i][0];
        if(sumf * c > qwgx * cnt) {
            qwgx = sumf, c = cnt;
            resv.clear();
            for(int i = 0; i < min(cnt, (int)gx.size()); i ++) {
                resv.push_back(gx[i][1]);
            }
        } 

    }
    cout << c << endl;
    for(auto &x : resv) cout << x << ' ';
    return 0;
}
