#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> nums(n), next_pos(n);
    long long tot = 0;

    for (int i = 0; i < n; i ++)
        cin >> nums[i], tot += nums[i];
    
    for (int i = n - 1; i >= 0; i --) 
        next_pos[i] = (i < n - 1 && nums[i] == 1 ? next_pos[i+1] : i);

    tot *= k;

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        int pt = i;
        long long p = 1, s = 0;
        while (pt < n) {
            if (next_pos[pt] != pt) {
                if (p % k == 0 && p / k - s > 0 && p / k - s <= next_pos[pt] - pt)
                    ans ++;
                s += next_pos[pt] - pt;
                pt = next_pos[pt];
            }
            else {
                if (tot / nums[pt] < p) break;
                p *= nums[pt];
                s += nums[pt];
                if (p == s * k) ans ++;
                pt += 1;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}