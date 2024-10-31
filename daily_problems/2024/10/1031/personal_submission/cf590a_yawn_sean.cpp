#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std; 

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v;
    
    int ans = 0;

    auto op = [&] (int l, int r) {
        ans = max(ans, (r - l - 1) / 2);
        for (int i = l; i < (l + r) / 2; i ++)
            nums[i] = nums[l];
        for (int i = (l + r) / 2; i < r; i ++)
            nums[i] = nums[r - 1];
    };

    int l = 0;
    for (int i = 1; i < n; i ++) {
        if (nums[i] == nums[i - 1]) {
            op(l, i);
            l = i;
        }
    }

    op(l, n);

    cout << ans << '\n';
    for (auto &x: nums)
        cout << x << ' ';

    return 0;
}