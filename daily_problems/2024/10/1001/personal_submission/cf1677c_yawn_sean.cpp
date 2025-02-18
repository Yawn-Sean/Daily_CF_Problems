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

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;

        vector<int> perm1(n), perm(n);
        for (auto &v: perm1)
            cin >> v, v --;
        
        for (auto &v: perm1)
            cin >> perm[v], perm[v] --;
        
        vector<int> vis(n, 0);
        int k = 0;

        for (int i = 0; i < n; i ++) {
            if (!vis[i]) {
                int cnt = 0;
                while (!vis[i]) {
                    vis[i] = 1;
                    i = perm[i];
                    cnt ++;
                }
                k += cnt / 2;
            }
        }
        cout << 2ll * k * (n - k) << '\n';
    }

    return 0;
}