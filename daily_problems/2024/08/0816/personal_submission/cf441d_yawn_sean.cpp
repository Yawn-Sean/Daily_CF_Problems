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

    vector<int> perm(n), vis(n);
    for (auto &v: perm) cin >> v, v --;

    int swaps = n;
    for (int i = 0; i < n; i ++) {
        if (!vis[i]) {
            swaps --;
            int j = i;
            while (!vis[j]) {
                vis[j] = 1;
                j = perm[j];
            }
        }
    }

    int target;
    cin >> target;

    cout << abs(swaps - target) << '\n';

    if (target > swaps) {
        for (int cnt = 0; cnt < target - swaps; cnt ++) {
            for (int i = 0; i < n; i ++) vis[i] = 0;
            int x = -1, y = -1;
            for (int i = 0; i < n; i ++) {
                if (!vis[i]) {
                    if (x == -1) x = i;
                    else  {
                        y = i;
                        break;
                    }
                    int j = i;
                    while (!vis[j]) {
                        vis[j] = 1;
                        j = perm[j];
                    }
                }
            }
            swap(perm[x], perm[y]);
            cout << x + 1 << ' ' << y + 1 << ' ';
        }
    }
    else {
        for (int cnt = 0; cnt < swaps - target; cnt ++) {
            for (int i = 0; i < n; i ++) vis[i] = 0;
            for (int i = 0; i < n; i ++) {
                if (perm[i] != i) {
                    int x = i, y = n;
                    while (!vis[i]) {
                        vis[i] = 1;
                        if (i != x) y = min(i, y);
                        i = perm[i];
                    }
                    swap(perm[x], perm[y]);
                    cout << x + 1 << ' ' << y + 1 << ' ';
                    break;
                }
            }
        }
    }

    return 0;
}