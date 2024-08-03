#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> nums(n);
    
    vector<int> large_endian_pairs;
    vector<int> little_endian_pairs;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i].first >> nums[i].second;
        if (nums[i].first < nums[i].second) {
            little_endian_pairs.push_back(i);
        } else {
            large_endian_pairs.push_back(i);
        }
    }

    vector<int> ret{};
    if (size(little_endian_pairs) > size(large_endian_pairs)) {
        sort(begin(little_endian_pairs), end(little_endian_pairs), [&](auto&& lhs, auto&& rhs) {
            return nums[lhs].second > nums[rhs].second;
        });
        ret = move(little_endian_pairs);
    } else {
        sort(begin(large_endian_pairs), end(large_endian_pairs), [&](auto&& lhs, auto&& rhs) {
            return nums[lhs].first < nums[rhs].first;
        });
        ret = move(large_endian_pairs);
    }

    cout << size(ret) << '\n';
    for (int i = 0; i < size(ret); ++i) {
        cout << ret[i] + 1 << " \n"[i == size(ret) - 1];
    }

    return 0;
}