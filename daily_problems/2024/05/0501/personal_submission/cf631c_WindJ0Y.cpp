#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<pair<int, int>> p(n);
    for (int i = 0; i < m; ++i) {
        int pos, op; cin >> op >> pos;
        while (p.size() && p.back().first <= pos) {
            p.pop_back();
        }
        if (p.empty() || p.back().second != op) {
            p.emplace_back(pos, op);
        }
    }

    if (p.front().second == 1) {
        sort(nums.begin(), nums.begin() + p.front().first);
    } else {
        sort(nums.begin(), nums.begin() + p.front().first, greater<int>());
    }

    vector<int> mirror_nums = nums;

    int s = 0, e = p.front().first - 1;
    for (int i = 0; i < p.size(); i ++) {
        int nxsize = (i == p.size() - 1 ? 0 : p[i + 1].first);
        for (int pos = p[i].first - 1; pos >= nxsize; pos--) {
            if (p[i].second == p[0].second) {
                nums[pos] = mirror_nums[e--];
            } else {
                nums[pos] = mirror_nums[s++];
            }
            
        }
    }

    for (auto elm : nums) {
        cout << elm << " ";
    }
}

int main(void) {
    
    ios::sync_with_stdio(false);

    int T{1};
    // cin >> T;
    while (T--) {
        solve();
    }

}