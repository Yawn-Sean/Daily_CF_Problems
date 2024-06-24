int n;

int lowbit(int x) {
    return x & -x;
}
void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int mx = -1;
    vector<int> res;
    for (int i = 0; i < 30; i ++) {
        int sum = (1 << 30) - 1;
        vector<int> ans;
        for (auto x : a) {
            if (x >> i & 1) {
                sum &= x;
                ans.push_back(x);
            }
        }
        sum = lowbit(sum);
        if (sum > mx) {
            mx = sum;
            res = move(ans);
        }
    }
    cout << sz(res) << endl;
    cout << res << endl;
}