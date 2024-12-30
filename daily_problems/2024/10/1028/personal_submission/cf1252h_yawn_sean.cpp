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

    vector<pair<int, int>> wls(n);
    long long ans = 0;

    for (int i = 0; i < n; i ++) {
        cin >> wls[i].first >> wls[i].second;
        if (wls[i].first > wls[i].second)
            swap(wls[i].first, wls[i].second);
        ans = max(ans, 1ll * wls[i].first * wls[i].second);
    }

    sort(wls.begin(), wls.end());

    int max_l = 0;
    for (int i = n - 1; i >= 0; i --) {
        ans = max(ans, 2ll * wls[i].first * min(wls[i].second, max_l));
        max_l = max(max_l, wls[i].second);
    }
    cout << ans / 2 << '.' << ans % 2 * 5;

    return 0;
}