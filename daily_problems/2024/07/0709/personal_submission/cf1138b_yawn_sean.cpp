#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s1, s2;
    cin >> n;
    cin >> s1 >> s2;

    vector<vector<int>> tmp(3);
    int cnt = 0;

    for (int i = 0; i < n; ) {
        cnt += s1[i] == '1';
        tmp[s1[i] - '0' + s2[i] - '0'].push_back(++i);
    }

    for (int i2 = 0; i2 <= tmp[2].size(); i2 ++) {
        int i1 = cnt - i2 * 2, i0 = n / 2 - i1 - i2;
        if (i0 >= 0 && i0 <= tmp[0].size() && i1 >= 0 && i1 <= tmp[1].size()) {
            for (int i = i0; i < tmp[0].size(); i ++) cout << tmp[0][i] << ' ';
            for (int i = i1; i < tmp[1].size(); i ++) cout << tmp[1][i] << ' ';
            for (int i = i2; i < tmp[2].size(); i ++) cout << tmp[2][i] << ' ';
            return 0;
        }
    }
    cout << -1;

    return 0;
}