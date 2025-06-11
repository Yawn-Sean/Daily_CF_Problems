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

    int n, a, M = 1e6 + 1;
    cin >> n >> a;

    vector<vector<int>> tmp(M);

    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        tmp[x].emplace_back(i);
    }

    for (int i = 1; i < M; i ++) {
        if (i != a && tmp[i].size() >= tmp[a].size()) {
            bool flg = true;
            for (int j = 0; j < tmp[a].size(); j ++) {
                if (tmp[i][j] > tmp[a][j]) {
                    flg = false;
                    break;
                }
            }
            if (flg) return cout << i, 0;
        }
    }
    cout << -1;

    return 0;
}