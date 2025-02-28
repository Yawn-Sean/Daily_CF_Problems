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

    int n, q, mod = 1e9 + 7;
    cin >> n >> q;

    string s;
    cin >> s;


    vector<int> acc_1(n + 1, 0), pw_2(n + 1, 1);
    for (int i = 0; i < n; i ++) {
        acc_1[i + 1] = acc_1[i] + (s[i] - '0');
        pw_2[i + 1] = pw_2[i] * 2 % mod;
    }

    while (q --) {
        int l, r;
        cin >> l >> r;
        l --;
        int ans = pw_2[r - l] - pw_2[r - l - (acc_1[r] - acc_1[l])];
        if (ans < 0) ans += mod;
        cout << ans << '\n';
    }

    return 0;
}