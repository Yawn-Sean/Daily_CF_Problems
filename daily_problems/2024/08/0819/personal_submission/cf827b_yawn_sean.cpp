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

    int n, k;
    cin >> n >> k;
    cout << (n - 1) / k * 2 + min((n - 1) % k, 2) << '\n';
    for (int i = 1; i <= k; i ++)
        cout << n << ' ' << i << '\n';
    for (int i = k + 1; i < n; i ++)
        cout << i - k << ' ' << i << '\n';

    return 0;
}