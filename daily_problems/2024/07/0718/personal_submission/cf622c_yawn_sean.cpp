#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;

    vector<int> lefts(n, 0), nums(n);
    cin >> nums[0];

    for (int i = 1; i < n; i ++) {
        cin >> nums[i];
        lefts[i] = (nums[i] == nums[i-1] ? lefts[i-1] : i);
    }

    while (q --) {
        int l, r, x;
        cin >> l >> r >> x;
        if (nums[r-1] != x) cout << r << '\n';
        else if (lefts[r-1] >= l) cout << lefts[r-1] << '\n';
        else cout << "-1\n";
    }

    return 0;
}