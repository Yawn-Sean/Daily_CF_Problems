#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
/*
    根号分治，由于内存限制，只能开一个一维数组，
    使用离线对每一个k单独处理
*/
const int N = 3e5 + 5;
int a[N];
const int B = 300;
ll sum[N];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int q;
    cin >> q;
    map<int, vector<pair<int, int>>> mp;
    vector<ll> ret(q);
    for (int idx = 0; idx < q; idx++) {
        int t, k;
        cin >> t >> k;
        if (k > B) {
            ll ans = 0;
            for (int i = t; i <= n; i += k) {
                ans += a[i];
            }
            ret[idx] = ans;
        } else {
            mp[k].push_back({t, idx});
        }
    }
    for (auto& [k, val] : mp) {
        for (int i = 1; i <= n; i++) {
            if (i <= k)
                sum[i] = a[i];
            else
                sum[i] = sum[i - k] + a[i];
        }
        for (auto [t, idx] : val) {
            int tmp = n - t;
            int last = t + (tmp / k) * k;
            int pre = max(t - k, 0);
            ret[idx] = sum[last] - sum[pre];
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ret[i] << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}