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

    int n, k, x;
    cin >> n >> k >> x;

    vector<int> nums(n), pref(n), suff(n);
    for (int i = 0; i < n; i ++) {
        cin >> nums[i];
        pref[i] = nums[i];
        suff[i] = nums[i];
    }
    
    for (int i = 1; i < n; i ++)
        pref[i] |= pref[i-1];
    
    for (int i = n - 1; i > 0; i --)
        suff[i-1] |= suff[i];
    
    long long ans = 0, cur = pow(x, k);

    for (int i = 0; i < n; i ++) {
        long long tmp = cur * nums[i];
        if (i) tmp |= pref[i-1];
        if (i + 1 < n) tmp |= suff[i+1];
        ans = max(ans, tmp);
    }
    cout << ans;

    return 0;
}