/*
考虑每个数与前面已加入的数的贡献,
如果当前数x放在左边,那么贡献为后面<x的数的数量,
如果当前数x放在右边,那么贡献为前面>x的数的数量.
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void update(vector<ll>& fenwick_tree, int idx, ll val) {
    while (idx < fenwick_tree.size()) {
        fenwick_tree[idx] += val;
        idx += idx & -idx;
    }
}

ll Sum(vector<ll>& fenwick_tree, int idx) {
    ll sum = 0;
    while (idx > 0) {
        sum += fenwick_tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}

vector<int> unique(vector<int>& nums) {
    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());
    sorted_nums.erase(unique(sorted_nums.begin(), sorted_nums.end()), sorted_nums.end());
    return sorted_nums;
}

ll solve(vector<int>& nums) {
    vector<int> sorted_nums = unique(nums);
    map<int, int> mp;
    for (int i = 0; i < sorted_nums.size(); ++i) {
        mp[sorted_nums[i]] = i + 1;
    }
    ll inversions = 0, cnt = 0;
    vector<ll> fenwick_tree(sorted_nums.size() + 1, 0);
    for (int num : nums) {
        int rank = mp[num];
        ll left = Sum(fenwick_tree, rank - 1);
        ll right = cnt - Sum(fenwick_tree, rank);
        update(fenwick_tree, rank, 1);
        inversions += min(left, right);
        cnt++;
    }
    return inversions;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << solve(nums) << endl;
    }
    return 0;
}
