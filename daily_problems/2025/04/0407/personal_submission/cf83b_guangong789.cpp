#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k, s = 0;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        s += v[i];
    }
    if (s < k) {
        cout << "-1\n";
        return;
    }
    // 二分找出最大完整循环的轮数
    int l = 0, r = 1e9, mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        int tmp = 0;
        for (int& x : v) {
            tmp += min(x, mid);
        }
        if (tmp <= k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    // left记录前r轮检查不完的人
    vector<int> left;
    for (int i = 0; i < n; ++i) {
        if (v[i] > r) {
            left.emplace_back(i);
        }
        k -= min(v[i], r);
        v[i] -= min(v[i], r);
    }
    // 最后还能检查前k个人
    for (int i = 0; i < k; ++i) {
        v[left[i]]--;
    }
    // 没检查到的人排到前面
    for (int i = k; i < left.size(); ++i) {
        if (v[left[i]]) {
            cout << left[i] + 1 << ' ';
        }
    }
    for (int i = 0; i < k; ++i) {
        if (v[left[i]]) {
            cout << left[i] + 1 << ' ';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
//    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}