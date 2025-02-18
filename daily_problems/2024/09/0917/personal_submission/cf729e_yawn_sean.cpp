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

    int n, s, ans = 0;
    cin >> n >> s;

    vector<int> cnt(n, 0);
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        if (i == s) ans += (x > 0);
        else cnt[x] ++;
    }

    int cur = 0;
    for (int i = 1; cur < n - 1; i ++) {
        if (cnt[i]) cur += cnt[i];
        else cur ++, ans ++;
    }
    cout << ans;

    return 0;
}