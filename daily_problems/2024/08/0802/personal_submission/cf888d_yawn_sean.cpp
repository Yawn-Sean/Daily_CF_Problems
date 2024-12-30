#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

long long comb(int x, int y) {
    if (y > x) return 0;
    long long ans = 1;
    for (int i = 0; i < y; i ++) {
        ans = ans * (x - i) / (i + 1);
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    long long ans = 1;
    if (k >= 2) ans += comb(n, 2);
    if (k >= 3) ans += 2 * comb(n, 3);
    if (k >= 4) ans += 9 * comb(n, 4);
    cout << ans;

    return 0;
}