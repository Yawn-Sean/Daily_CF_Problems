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

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        ans ^= x;
    }

    auto pref_xor = [&] (int x) -> int {
        if (x % 4 == 0) return x;
        else if (x % 4 == 1) return 1;
        else if (x % 4 == 2) return x + 1;
        return 0;
    };

    for (int i = 1; i <= n; i ++) {
        int x = n % (2 * i);
        if (x >= i) ans ^= pref_xor(i - 1) ^ pref_xor(x - i);
        else ans ^= pref_xor(x);
    }

    cout << ans;

    return 0;
}