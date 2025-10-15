#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    string chars = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

    while (t --) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<string> grid(n);
        for (int i = 0; i < n; i ++)
            cin >> grid[i];
        
        int total = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                total += (grid[i][j] == 'R');
            }
        }

        int a = total / k, b = total % k;
        map<int, int> cnt;
        cnt[a + 1] = b;
        cnt[a] = k - b;

        vector<vector<int>> ans(n, vector<int>(m, -1));

        int x = 0, y = 0, dy = 1;

        auto op = [&] () -> void {
            if (y + dy >= 0 && y + dy < m) y += dy;
            else x ++, dy = -dy;
        };

        for (int i = 0; i < k; i ++) {
            int c = (grid[x][y] == 'R');
            ans[x][y] = i;
            op();

            while (cnt[c] == 0) {
                c += (grid[x][y] == 'R');
                ans[x][y] = i;
                op();
            }
            cnt[c] --;
        }

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                cout << (ans[i][j] == -1 ? chars[k - 1] : chars[ans[i][j]]);
            }
            cout << '\n';
        }
    }

    return 0;
}