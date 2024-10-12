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

    auto query = [&] (int x, int y) {
        cout << 1 << ' ' << x << ' ' << y << endl;
        string s;
        cin >> s;
        return s[0] == 'T';
    };

    auto f = [&] (int l, int r) -> int {
        while (l < r) {
            int m = (l + r) / 2;
            if (query(m, m + 1)) r = m;
            else l = m + 1;
        }
        return r;
    };

    int n, k;
    cin >> n >> k;
    int x, y;
    x = f(1, n);
    y = f(1, x - 1);
    if (y == 0 || !query(y, x)) y = f(x + 1, n);

    cout << 2 << ' ' << x << ' ' << y;

    return 0;
}