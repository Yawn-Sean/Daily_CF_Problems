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

    int n, a, b;
    cin >> n >> a >> b;

    map<long long, int> vis1;
    map<pair<int, int>, int> vis2;
    
    long long ans = 0;

    while (n --) {
        int x, vx, vy;
        cin >> x >> vx >> vy;

        ans += vis1[-1ll * a * vx + vy];
        ans -= vis2[{vx, vy}];

        vis1[-1ll * a * vx + vy] ++;
        vis2[{vx, vy}] ++;
    }
    cout << ans * 2;

    return 0;
}