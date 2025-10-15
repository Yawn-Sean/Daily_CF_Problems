#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    i64 k;
    cin >> n >> k;
    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    i64 left = 0, right = *max_element(a.begin(), a.end()) + 1;
    while (left < right) {
        i64 mid = (left + right) / 2;
        i64 tot = 0;
        for (int i = 0; i < n; i++) {
            tot += min(mid, 1ll * a[i]);
        }

        if (tot <= k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    // >的第一个位置
    // --就是<=
    left--;
    // cout << left << '\n';

    i64 sm = 0;
    for (int i = 0; i < n; i++) {
        sm += min(left, a[i]);
        a[i] -= left;
    }
    k -= sm;

    vector<int> tmp, ans;
    for (int i = 0; i < n; i++) {
        if (a[i] <= 0) { continue; }
        else {
            if (k > 0) {
                k--; a[i]--;
                if (a[i] > 0) {
                    tmp.push_back(i + 1);
                }
            } else {
                ans.push_back(i + 1);
            }
        }
    }

    if (k > 0) {
        cout << -1 << '\n';
    } else {
        for (auto&x: ans) { cout << x << ' '; }
        for (auto&x: tmp) { cout << x << ' '; }
    }
    return 0;
}
