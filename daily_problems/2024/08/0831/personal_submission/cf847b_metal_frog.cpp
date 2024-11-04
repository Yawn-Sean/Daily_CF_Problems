const int N = 2e5 + 7;
vector<int> res[N];
 
void solve() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    set<int> dp;
    map<int, int> rec;
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (dp.size() == 0) {
            rec[num[i]] = len;
            res[len].emplace_back(num[i]);
            len++;
            dp.insert(num[i]);
        } else {
            auto it = dp.lower_bound(num[i]);
            if (it != dp.begin()) {
                it--;
                int val = *it;
                dp.erase(val);
                int idx = rec[val];
                res[idx].emplace_back(num[i]);
                rec[num[i]] = idx;
            } else {
                rec[num[i]] = len;
                res[len].emplace_back(num[i]);
                len++;
            }
            dp.insert(num[i]);
        }
    }
    for (int i = 0; i < len; i++) {
        for (int x : res[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
 
