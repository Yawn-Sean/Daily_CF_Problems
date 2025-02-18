 /*
P = 2 * (a + b)
S = a * b
4 * (a + b)^2 / (a * b) = 4 * (a^2 + 2ab + b^2) / (ab) = 8 + 4 * (a^2 + b^2) / ab
a^2 + b^2 >= 2ab，所以 a + b 确定时，a = b 时 P^2 / S 最小，为 16
需要有 2 个 a 和 2 个 b
如果相等的话需要有 4 个，直接选了
如果实在没有 4 个相等的，需要找 (a^2 + b^2) / ab 最小的，其实就是 a 和 b 要尽量接近，取相邻的即可
*/
 
int n, a[N];
 
void meibao() {
    cin >> n;
    map<int, int> cnt;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<int> b;
    for (auto it : cnt) {
        int k = it.x, v = it.y;
        if (v >= 4) {
            cout << k << " " << k << " " << k << " " << k << '\n';
            return;
        }
        if (v < 2) continue;
        b.pb(k);
    }
    sort(b.begin(), b.end());
    double res = INF;
    vector<int> choose;
    for (int i = 1; i < b.size(); i++) {
        double cur = (b[i] + b[i - 1]) * (b[i] + b[i - 1]) * 4.0 / (b[i] * b[i - 1]);
        if (cur < res) {
            res = cur;
            choose.clear();
            choose.pb(b[i - 1]);
            choose.pb(b[i]);
        }
    }
    cout << choose[0] << " " << choose[0] << " " << choose[1] << " " << choose[1] << "\n";
}
 
