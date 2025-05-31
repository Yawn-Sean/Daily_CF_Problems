#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector<i64> nums(n);
    i64 tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        tot += nums[i];
    }

    i64 target = tot / n;
    for (int i = 0; i < n; i++) {
        nums[i] -= target;
    }
    vector<pair<int,int>> s1, s2;
    i64 ans = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] < 0) {
            s1.emplace_back(nums[i], i);
        } else if (nums[i] > 0) {
            s2.emplace_back(nums[i], i);
        }
    }

    int j = 0;
    int m = s2.size();
    for (auto& [need, idx]: s1) {
        i64 cur = 0;
        while (j < m && need < 0) {
            i64 add = min(s2[j].first, -need);
            s2[j].first -= add;
            need += add;

            ans += add * abs(idx - s2[j].second);
            if (s2[j].first == 0) {
                ++j;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
