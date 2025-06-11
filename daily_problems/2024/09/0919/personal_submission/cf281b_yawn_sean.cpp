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

    int x, y, n;
    cin >> x >> y >> n;

    int de = 1, nu = 0;
    long long diff_de = x, diff_nu = y;

    for (int b = 1; b <= n; b ++) {
        int v = 1ll * b * x / y;
        for (int a = v; a <= v + 1; a ++) {
            long long ndiff_de = abs(1ll * x * b - 1ll * y * a), ndiff_nu = 1ll * b * y;
            if (ndiff_de * diff_nu < diff_de * ndiff_nu) {
                de = b, nu = a;
                diff_de = ndiff_de, diff_nu = ndiff_nu;
            }
        }
    }
    cout << nu << '/' << de;

    return 0;
}