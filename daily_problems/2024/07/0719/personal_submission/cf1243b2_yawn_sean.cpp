#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
        string s1, s2;
        cin >> s1 >> s2;

        vector<pair<int, int>> ops;

        function<void(int, int)> op = [&] (int x, int y) {
            swap(s1[x], s2[y]);
            ops.push_back({x, y});
        };

        bool flg = true;
        for (int i = 0; i < n; i ++) {
            if (s1[i] == s2[i]) continue;
            bool tmpflg = false;
            for (int j = i + 1; j < n; j ++) {
                if (s1[i] == s1[j]) {
                    op(j, i);
                    tmpflg = true;
                    break;
                }
            }
            if (!tmpflg)
                for (int j = i + 1; j < n; j ++) {
                    if (s1[i] == s2[j]) {
                        op(i + 1, j);
                        op(i + 1, i);
                        tmpflg = true;
                        break;
                    }
                }
            if (!tmpflg) {
                flg = false;
                break;
            }
        }
        if (flg) {
            cout << "Yes\n";
            cout << ops.size() << '\n';
            for (auto &[x, y]: ops)
                cout << x + 1 << ' ' << y + 1 << '\n';
        }
        else 
            cout << "No\n";
    }

    return 0;
}