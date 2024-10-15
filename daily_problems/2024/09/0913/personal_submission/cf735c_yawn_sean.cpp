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

    long long n, v1 = 2, v2 = 1;
    cin >> n;

    int ans = 0;
    while (v1 <= n) {
        v1 += v2;
        v2 = v1 - v2;
        ans ++;
    }
    cout << ans;

    return 0;
}