#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &x: nums) 
        cin >> x;

    for (int i = 29; i >= 0; i--) {
        vector<int> ans;
        int msk = (1 << i) - 1;
        for (auto &x: nums)
            if (x >> i & 1)
                ans.push_back(x), msk &= x;
        if (!msk) {
            cout << (int)ans.size() << '\n';
            for (auto &x: ans) cout << x << ' ';
            return 0;
        }
    }

    return 0;
}