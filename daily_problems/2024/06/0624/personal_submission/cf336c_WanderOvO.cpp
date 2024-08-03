/*
想让最低位的 1 的位尽可能高
枚举最低位的 1 是在哪位
需要选最多的数
考虑所有的第 i 位为 1 的数
把所有这些数都选上，能尽可能保证低位都是 0
*/

int T;
int n, a[N];

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> res;
    for (int i = 0; i <= 30; i++) {
        vector<int> b;
        int val = -1;
        for (int j = 1; j <= n; j++) {
            if ((a[j] >> i) & 1) {
                b.pb(a[j]);
            }
        }
        if (b.size() > 0) {
            for (int j = 0; j < b.size(); j++) {
                val &= b[j];
            }
            bool ok = true;
            for (int j = 0; j < i; j++) {
                if ((val >> j) & 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                res = b;
            }
        }
    }
    cout << res.size() << "\n";
    for (auto val : res) {
        cout << val << " ";
    }
    cout << "\n";
}      