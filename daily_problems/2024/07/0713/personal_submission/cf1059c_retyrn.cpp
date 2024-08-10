int n;

vector<int> f(int n) {
    if (n == 1) {
        vector<int> res = {1};
        return res;
    }
    if (n == 2) {
        vector<int> res = {1, 2};
        return res;
    }
    if (n == 3) {
        vector<int> res = {1, 1, 3};
        return res;
    }
    
    int len = n - n / 2;
    vector<int> res;
    for (int i = 0; i < len; i ++) {
        res.push_back(1);
    }
    auto v = f(n - len);
    for (auto x : v) {
        res.push_back(x * 2);
    }
    return res;
}

void solve() {
    cin >> n;
    auto v = f(n);
    cout << v << endl;
}