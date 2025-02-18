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

    vector<int> perm(n);
    for (auto &v: perm)
        cin >> v, v --;
    
    vector<int> vis(n, 0);
    int cnt = 0;

    for (int i = 0; i < n; i ++) {
        if (!vis[i]) {
            while (!vis[perm[i]]) {
                i = perm[i];
                vis[i] = 1;
            }
            cnt ++;
        }
    }
    
    int v = 1, x;
    while (n --) {
        cin >> x;
        v ^= x;
    }
    cout << (cnt > 1 ? cnt : 0) + v;

    return 0;
}
