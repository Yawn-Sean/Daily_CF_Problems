#include<bits/stdc++.h>

#pragma GCC optimize("O3,Ofast,unroll-loops")

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    map<string, int> mp;

    vector<int> flg(n, 0);
    vector<vector<int>> vals(n, vector<int>(m));
    vector<array<int, 3>> ops(n);

    mp["?"] = 0;

    for (int i = 1; i <= n; i ++) {
        string s;
        cin >> s;

        mp[s] = i;
        cin >> s >> s;

        if (s[0] == '0' || s[0] == '1') {
            for (int j = 0; j < m; j ++)
                vals[i - 1][j] = s[j] - '0';
        }
        else {
            flg[i - 1] = 1;

            ops[i - 1][0] = mp[s];
            cin >> s;

            if (s[0] == 'X') ops[i - 1][1] = 0;
            else if (s[0] == 'O') ops[i - 1][1] = 1;
            else ops[i - 1][1] = 2;

            cin >> s;
            ops[i - 1][2] = mp[s];
        }
    }

    string ans0, ans1;

    for (int i = 0; i < m; i ++) {
        int c0 = 0, c1 = 0;
        vector<int> cur0(n), cur1(n);

        for (int j = 0; j < n; j ++) {
            if (flg[j]) {
                auto [x, o, y] = ops[j];

                int x0 = (x ? cur0[x - 1] : 0);
                int x1 = (x ? cur1[x - 1] : 1);

                int y0 = (y ? cur0[y - 1] : 0);
                int y1 = (y ? cur1[y - 1] : 1);

                if (o == 0) cur0[j] = x0 ^ y0, cur1[j] = x1 ^ y1;
                else if (o == 1) cur0[j] = x0 | y0, cur1[j] = x1 | y1;
                else cur0[j] = x0 & y0, cur1[j] = x1 & y1;
            }
            else cur0[j] = vals[j][i], cur1[j] = vals[j][i];

            c0 += cur0[j], c1 += cur1[j];
        }

        if (c0 <= c1) ans0 += '0';
        else ans0 += '1';

        if (c0 >= c1) ans1 += '0';
        else ans1 += '1';
    }

    cout << ans0 << '\n' << ans1;

    return 0;
}
