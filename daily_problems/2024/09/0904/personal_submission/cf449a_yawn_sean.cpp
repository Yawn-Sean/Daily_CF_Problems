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

    int n, m, k;
    cin >> n >> m >> k;

    auto f = [&] (int x) -> long long {
        return 1ll * x * (m / max(1, k - n / x + 2));
    };

    long long ans = 0;
    for (int i = 1; i <= n && i < 40000; i ++)
        ans = max(ans, f(i)), ans = max(ans, f(n / i));

    cout << (ans ? ans : -1);

    return 0;
}