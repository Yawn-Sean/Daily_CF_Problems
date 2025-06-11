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

    auto query = [&] (int x, int y) -> bool {
        cout << x << ' ' << y << '\n';
        cout.flush();
        string s;
        cin >> s;
        return s[0] == 'b';
    };

    int n;
    cin >> n;

    int l = 0, r = 1e9;
    bool flg = query(r, r);

    for (int i = 0; i < n - 1; i ++) {
        int m = (l + r) / 2;
        if (query(m, m) == flg) r = m;
        else l = m;
    }

    cout << l << ' ' << r << ' ' << r << ' ' << l;

    return 0;
}