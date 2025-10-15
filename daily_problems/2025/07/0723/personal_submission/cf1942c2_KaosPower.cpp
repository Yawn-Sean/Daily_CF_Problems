#include<bits/stdc++.h>

#pragma GCC optimize("O3,Ofast,unroll-loops")

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> nums(x);
        for (auto &v: nums) cin >> v;

        sort(nums.begin(), nums.end());

        vector<int> vs;
        int cnt = x, v;

        for (int i = 1; i < x; i ++) {
            v = nums[i] - nums[i - 1] - 1;
            if (v & 1) vs.emplace_back(v);
        }

        v = nums[0] + n - nums[x - 1] - 1;
        if (v & 1) vs.emplace_back(v);

        sort(vs.begin(), vs.end());

        for (auto &v: vs) {
            if (y >= v / 2) {
                y -= v / 2;
                cnt += v;
            }
        }

        cnt += y * 2;
        cout << min(cnt, n) - 2 << '\n';
    }

    return 0;
}
