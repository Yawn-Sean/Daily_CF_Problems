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

    int n, p;
    cin >> n >> p;

    vector<long double> probs(n);

    for (int i = 0; i < n; i ++) {
        int l, r;
        cin >> l >> r;
        probs[i] = (long double)1.0 * (r / p - (l - 1) / p) / (r - l + 1);
    }

    long double ans = 0;
    for (int i = 0; i < n; i ++) {
        ans += probs[i];
        ans += probs[(i + 1) % n];
        ans -= probs[i] * probs[(i + 1) % n];
    }

    cout << fixed << setprecision(20) << ans * 2000;

    return 0;
}