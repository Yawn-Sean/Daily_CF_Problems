#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    if (s1.size() != s2.size()) {
        cout << "-1\n";
        return 0;
    }

    int inf = 1e8;
    vector<vector<int>> dist(26, vector<int>(26, inf));

    for (int i = 0; i < 26; i ++) dist[i][i] = 0;
    
    int n;
    cin >> n;

    while (n --) {
        char c1, c2;
        int d;
        cin >> c1 >> c2 >> d;
        int x1 = c1 - 'a', x2 = c2 - 'a';
        dist[x1][x2] = min(dist[x1][x2], d);
    }

    for (int i = 0; i < 26; i ++)
        for (int j = 0; j < 26; j ++)
            for (int k = 0; k < 26; k ++)
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
    
    vector<vector<int>> ans(26, vector<int>(26, inf));
    vector<vector<int>> chars(26, vector<int>(26, -1));

    for (int i = 0; i < 26; i ++)
        for (int j = 0; j < 26; j ++)
            for (int k = 0; k < 26; k ++)
                if (dist[i][k] + dist[j][k] < ans[i][j])
                    ans[i][j] = dist[i][k] + dist[j][k], chars[i][j] = k;
    
    int len = s1.size();
    int res = 0;
    string final_str(len, 'a');

    for (int i = 0; i < len; i ++) {
        int x = s1[i] - 'a', y = s2[i] - 'a';
        if (chars[x][y] == -1) {
            cout << "-1\n";
            return 0;
        }
        res += ans[x][y], final_str[i] += chars[x][y];
    }
    cout << res << '\n' << final_str << '\n';

    return 0;
}