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

    int a, b, mod = 1e9 + 7;
    cin >> a >> b;
    cout << ((1ll * a * (a + 1) / 2 % mod) * b % mod + a) % mod * (1ll * b * (b - 1) / 2 % mod) % mod;

    return 0;
}