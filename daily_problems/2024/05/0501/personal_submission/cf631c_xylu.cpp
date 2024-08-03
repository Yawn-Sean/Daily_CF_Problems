#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    vector<pair<int, int>> ops;
    for (int i = 0; i < n; ++i) cin >> nums[i];
    for (int i = 0; i < m; ++i) {
        int t, r;
        cin >> t >> r;
        while (ops.size() && ops.back().second <= r) ops.pop_back();
        ops.push_back({t, r});
    }
    ops.push_back({0, 0});
    vector<int> tmp(nums.begin(), nums.begin() + ops[0].second);
    sort(tmp.begin(), tmp.end());
    int l = 0, r = ops[0].second - 1;
    for (int i = 0; i < ops.size() - 1; ++i) {
        if (ops[i].first == 1) {
            for (int j = ops[i].second-1; j >= ops[i+1].second; --j) {
                nums[j] = tmp[r--];
            }
        } else {
            for (int j = ops[i].second-1; j >= ops[i+1].second; --j) {
                nums[j] = tmp[l++];
            }
        }
    }
    for (int i = 0; i < n; ++i) cout << nums[i] << " ";

    return 0;
}
