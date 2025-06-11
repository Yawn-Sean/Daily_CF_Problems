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

    int a, b, mod;
    cin >> a >> b >> mod;

    int x = 1e9, v = 0;
    x %= mod;

    for (int i = 0; i <= a && i < mod; i ++) {
        if (v > b) {
            string s = to_string(i);
            s = string(9 - s.size(), '0') + s;
            cout << "1 " << s;
            return 0;
        }
        v = (v + mod - x) % mod;
    }
    cout << 2;

    return 0;
}