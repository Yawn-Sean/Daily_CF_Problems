#include <bits/stdc++.h>
using namespace std;

bool solve(int n, vector<int> nums, vector<int> &ops) {
    for (int i = n - 1; i >= 0; --i) {
        bool found = false;
        for (int j = i; j >= 0; --j) {
            if (nums[j] == j + 1) {
                ops.push_back(nums[j]);
                nums.erase(nums.begin() + j);
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    reverse(ops.begin(), ops.end());
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n), ops;
    for (int &x : nums) cin >> x;

    if (solve(n, nums, ops)) {
        cout << "YES\n";
        for (int x : ops) cout << x << ' ';
    } else {
        cout << "NO";
    }
    return 0;
}
