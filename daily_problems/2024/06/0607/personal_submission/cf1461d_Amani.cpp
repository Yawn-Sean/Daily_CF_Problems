#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        ranges::sort(arr);
        vector<long long> prefix(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
        set<int> res;
        stack<pair<int, int>> stk;
        stk.push({0, n - 1});
        while (!stk.empty()) {
            auto [l, r] = stk.top();
            stk.pop();
            if (prefix[r + 1] - prefix[l] <= 1e9) {
                res.insert(prefix[r + 1] - prefix[l]);
            }
            if (arr[l] != arr[r]) {
                int idx = upper_bound(arr.begin() + l, arr.begin() + r, (arr[l] + arr[r]) / 2) - arr.begin();
                if (idx <= r)
                    stk.push({idx, r});
                if (idx - 1 >= l)
                    stk.push({l, idx - 1});
            }
        }
        while (q--) {
            int s;
            cin >> s;
            cout << (res.count(s) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}
