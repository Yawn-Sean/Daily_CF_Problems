#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    int l = -1, r = m;
    auto check = [&](int x) {
        int pre = 0;
        for (int y : nums) {
            if (y < pre) {
                if (pre - y > x) return false;
            } else if (pre + m - y > x) {
                pre = y;
            } 
        }
        return true;
    };
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;

    return 0;
}
