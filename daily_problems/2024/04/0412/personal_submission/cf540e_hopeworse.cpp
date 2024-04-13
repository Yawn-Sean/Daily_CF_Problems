// link : https://codeforces.com/contest/540/submission/256185500

void solve() {
    int n;
    cin >> n;
    set<int> s;
    vector<PII> ask;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        s.insert(x);
        s.insert(y);
        ask.emplace_back(x, y);
    }
 
    int l = 1;
    map<int, int> mp;
    vector<pair<int, int>> arr;
    for (auto i: s) {
        if (l < i) {
            mp[i - 1] = arr.size();
            arr.emplace_back(i - 1, (i - 1) - l + 1);
        }
        mp[i] = arr.size();
        arr.emplace_back(i, 1);
        l = i + 1;
    }
//    debug(mp);
    vector<int> fw(arr.size() + 100);
    auto swaps = [&](int x, int y) {
        int lenx = mp[x];
        int leny = mp[y];
        swap(arr[lenx], arr[leny]);
    };
    auto get = [&](int x) {
        int res = 0;
        for (int i = x; i; i -= i & -i) {
            res += fw[i];
        }
        return res;
    };
    auto add = [&](int x, int y) {
        for (int i = x; i < fw.size(); i += i & -i) {
            fw[i] += y;
        }
    };
 
    for (auto [x, y]: ask) {
        swaps(x, y);
    }
 
    int ans = 0;
    debug(arr);
    debug(mp);
    for (int i = arr.size() - 1; i >= 0; i--) {
        ans += get(mp[arr[i].first] + 1) * arr[i].second;
        debug(i, ans);
        debug(get(mp[arr[i].first] + 1), arr[i].second);
//        debug(ans);
//        debug(mp[arr[i].first] + 1, get(arr[i].first + 1));
        add(mp[arr[i].first] + 1, arr[i].second);
//        debug("add", mp[arr[i].first] + 1, arr[i].second);
 
    }
    cout << ans << endl;
 
}
