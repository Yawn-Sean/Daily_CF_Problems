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
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> cnt(n);
    vector<bool> check(n + 1);
    int ans = 0;

    for (int i = 1; i <= n; i ++) {
        if (n % i == 0) {
            for (int j = 0; j < n; j ++)
                cnt[j % i] ^= s[j] - '0';
            check[i] = true;
            for (int j = 0; j < i; j ++)
                if (cnt[j])
                    cnt[j] = 0, check[i] = false;
        }
        ans += check[__gcd(i, n)];
    }
    cout << ans;

    return 0;
}