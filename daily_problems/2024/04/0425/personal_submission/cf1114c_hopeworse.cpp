void solve() {
    int k, n;
    cin >> k >> n;
    vector<pair<int, int>> p;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            p.emplace_back(i, cnt);
        }
    }
    if (n != 1) {
        p.emplace_back(n, 1);
    }

    int mins = inf;

    for (auto [i, j]: p) {
        debug(i, j);
        int mk = k;
        int aa = 0;
        while (mk) {
            mk /= i;
            aa += mk;
        }
//        int b = 0;
//        debug(aa);
//        while (aa >= j) {
//            b++;
//            j *= j;
//        }
        mins = min(mins,aa/j);
    }
    cout << mins << endl;

}
