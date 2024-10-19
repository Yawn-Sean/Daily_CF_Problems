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

    int n, ans = 0;
    cin >> n;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            int x;
            cin >> x;
            if (i == j) ans ^= x;
        }
    }

    int q;
    cin >> q;
    
    while (q --) {
        int t, x;
        cin >> t;
        if (t == 3) cout << ans;
        else cin >> x, ans ^= 1;
    }

    return 0;
}