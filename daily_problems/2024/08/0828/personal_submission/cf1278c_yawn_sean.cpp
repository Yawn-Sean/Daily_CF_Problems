#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;
        vector<int> nums(2 * n);
        for (auto &v: nums) cin >> v;

        int cur = n;
        vector<int> ma_cnt(2 * n + 1, -n);
        ma_cnt[cur] = 0;

        for (int i = 0; i < n; i ++) {
            cur += (nums[i] == 1 ? 1 : -1);
            ma_cnt[cur] = i + 1;
        }

        cur = n;
        int ma = ma_cnt[cur];
        for (int i = 2 * n - 1; i >= n; i --) {
            cur -= (nums[i] == 1 ? 1 : -1);
            ma = max(ma, ma_cnt[cur] + 2 * n - i);
        }
        cout << 2 * n - ma << '\n';
    }

    return 0;
}