#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<i64> nums(n), acc(n + 1, 0);
        for (int i = 0; i < n; i++) cin >> nums[i];
        for (int i = 0; i < n; i++) acc[i + 1] = acc[i] + nums[i];

        i64 ans = 0;

        vector<int> stk;
        vector<i64> stk_acc;
        stk.push_back(n + 1);
        stk_acc.push_back(0);

        for (int i = n; i >= 0; i--) {
            while (stk.back() != n + 1 && acc[i] >= acc[stk.back()]) {
                stk_acc.pop_back();
                stk.pop_back();
            }

            stk_acc.push_back(stk_acc.back() + (i64)(stk.back() - i) * acc[i]);
            stk.push_back(i);

            ans += stk_acc.back() - (i64)(n + 1 - i) * acc[i];
        }

        cout << ans << "\n";
    }
    return 0;
}
