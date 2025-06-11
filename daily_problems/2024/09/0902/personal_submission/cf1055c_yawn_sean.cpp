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

    int la, ra, ta, lb, rb, tb;
    cin >> la >> ra >> ta >> lb >> rb >> tb;

    int a = ra - la + 1, b = rb - lb + 1, g = __gcd(ta, tb), x = la - lb;
    x = (x % g + g) % g;
    cout << max({0, min(x + a, b) - x, min(x - g + a, b)});

    return 0;
}