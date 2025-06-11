void Solve() {
    int n;cin >> n;
    vector<vector<int>> a(200001);
    vector<int> s(200001);
    for (int i = 1;i <= n;i++) {
        int m, k;cin >> m >> k;
        a[m].push_back(k);
        s[m] += k;
    }
    for (int i = 1;i <= n;i++) {
        sort(a[i].begin(), a[i].end());
    }
    auto cmp = [&](array<int, 2> u, array<int, 2> v) {
        if (u[0] * v[1] < v[0] * u[1]) return 1;
        return 0;
        };
    array<int, 2> ans = { -1,1 };int res = 0;
    for (int i = 1;i <= 20;i++) {
        vector<int> vec;
        for (int j = 1;j <= 2e5;j++) {
            auto& b = a[j];
            int sum = 0;
            for (auto e : b) {
                sum += min(e, i);
            }
            if (sum) vec.push_back(sum);
        }
        sort(vec.begin(), vec.end(), greater<>());
        int sum = 0;
        for (int j = 0;j < vec.size() and j < i;j++) {
            sum += vec[j];
        }
        int g = gcd(i, sum);array<int, 2> t = { sum / g,i / g };
        if (cmp(ans, t)) ans = t, res = i;
    }
    vector<array<int, 2>> eve;
    for (int i = 1;i <= 2e5;i++) {
        if (s[i]) eve.push_back({ s[i],i });
    }
    sort(eve.begin(), eve.end(), greater<>());
    eve.insert(eve.begin(), {});
    int sum = 0;
    for (int i = 1;i < eve.size();i++) {
        sum += eve[i][0];
        if (i >= 21) {
            int g = gcd(i, sum);array<int, 2> t = { sum / g,i / g };
            if (cmp(ans, t)) ans = t, res = i;
        }
    }
    cout << res << endl;
    if (res >= 20) {
        for (int i = 0;i < res;i++) {
            cout << eve[i][1] << ' ';
        }
    }
    else {
        vector<array<int, 2>> vec;
        for (int j = 1;j <= 2e5;j++) {
            auto& b = a[j];
            int sum = 0;
            for (auto e : b) {
                sum += min(e, res);
            }
            if (sum) vec.push_back({ sum,j });
        }
        sort(vec.begin(), vec.end(), greater<>());
        for (int i = 0;i < res;i++) {
            cout << vec[i][1] << ' ';
        }
        cout << endl;
    }
}
