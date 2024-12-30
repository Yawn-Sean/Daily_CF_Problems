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

    int n, m;
    cin >> n >> m;

    vector<int> ls(m), rs(m);
    set<pair<int, int>> vis;

    for (int i = 0; i < m; i ++) {
        cin >> ls[i] >> rs[i];
        ls[i] --, rs[i] --;
        if (ls[i] > rs[i]) swap(ls[i], rs[i]);
        vis.emplace(ls[i], rs[i]);
    }

    int tmp = n;
    for (int i = 2; i <= n; i ++) {
        if (tmp % i == 0) {
            while (tmp % i == 0) tmp /= i;
            int x = n / i;
            bool flg = true;
            for (int j = 0; j < m; j ++) {
                int nl = (ls[j] + x) % n, nr = (rs[j] + x) % n;
                if (nl > nr) swap(nl, nr);
                if (vis.find({nl, nr}) == vis.end()) {
                    flg = false;
                    break;
                }
            }
            if (flg) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";

    return 0;
}