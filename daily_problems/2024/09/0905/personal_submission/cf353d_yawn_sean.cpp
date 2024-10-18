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

    string s;
    cin >> s;

    int ans = 0, cur = 0;

    for (auto c: s) {
        if (c == 'M') cur ++;
        else if (cur) ans = max(ans + 1, cur);
    }
    cout << ans;

    return 0;
}