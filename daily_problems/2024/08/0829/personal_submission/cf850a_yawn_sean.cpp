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
    if (n >= 34) cout << 0;
    else {
        vector<vector<int>> pts(5, vector<int>(n));
        for (int i = 0; i < n; i ++) 
            for (int j = 0; j < 5; j ++)
                cin >> pts[j][i];
        
        vector<int> ans;
        for (int i = 0; i < n; i ++) {
            bool flg = true;
            for (int j = 0; j < n; j ++) {
                for (int k = 0; k < j; k ++) {
                    int res = 0;
                    for (int d = 0; d < 5; d ++) {
                        res += (pts[d][k] - pts[d][i]) * (pts[d][j] - pts[d][i]);
                    }
                    if (res > 0) flg = false;
                }
            }
            if (flg) ans.emplace_back(i);
        }
        cout << ans.size() << '\n';
        for (auto &x: ans) cout << x + 1 << ' ';
    }

    return 0;
}