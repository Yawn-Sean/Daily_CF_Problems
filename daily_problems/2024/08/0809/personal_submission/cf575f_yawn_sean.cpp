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

    int n, x;
    cin >> n >> x;
    int l = x, r = x;
    long long ans = 0;

    while (n --) {
        int nl, nr;
        cin >> nl >> nr;
        if (r < nl) {
            ans += nl - r;
            l = r;
            r = nl;
        }
        else if (l > nr) {
            ans += l - nr;
            r = l;
            l = nr;
        }
        else {
            l = max(l, nl);
            r = min(r, nr);
        }
    }
    cout << ans;

    return 0;
}