#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; i ++)
        cin >> nums[i];
    
    vector<int> right(2e5 + 1), cnt(2e5 + 1);
    for (int i = 0; i < n; i ++) {
        cnt[nums[i]] ++;
        right[nums[i]] = i;
    }

    int l = 0, r = 0, ans = 0, ma = 0;
    for (int i = 0; i < n; i ++) {
        if (r < i) 
            ans += r - l + 1 - ma, l = i, r = i, ma = 0;
        r = max(r, right[nums[i]]);
        ma = max(ma, cnt[nums[i]]);
    }

    ans += r - l + 1 - ma;
    cout << ans << '\n';

    return 0;
}