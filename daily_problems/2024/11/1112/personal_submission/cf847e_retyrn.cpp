int n;
string s;

void solve() {
    cin >> n;
    cin >> s;
    
    vector<int> per, food;
    for (int i = 0; i < n; i ++) {
        if (s[i] == 'P') per.push_back(i);
        else if (s[i] == '*') food.push_back(i);
    }
    
    auto check = [&](int x) -> bool {
        int j = 0;
        for (auto p : per) {
            // 计算p可以走到最右端是多少
            if (food[j] < p and p - food[j] > x) return false;
            int p1 = (food[j] < p ? x - p + food[j] + food[j] : p + x);
            int p2 = (food[j] < p ? (x - p + food[j]) / 2 + p : p + x);
            int r = max(p1, p2);
            while (j < sz(food) and food[j] <= r) {
                j ++;
            }
            if (j == sz(food)) return true;
        }
        return false;
    };
    
    int l = 1, r = n * 2;
    while (l < r) {
        auto mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}