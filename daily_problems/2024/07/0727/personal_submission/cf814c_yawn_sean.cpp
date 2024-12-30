#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<int>> saved(26, vector<int>(n + 1));
    for (int i = 0; i < 26; i ++) {
        for (int j = 1; j <= n; j ++) {
            int l = 0, r = 0, cur = 0;
            while (l < n) {
                while (r < n && cur + (s[r] - 'a' != i) <= j)
                    cur += (s[r ++] - 'a' != i);
                saved[i][j] = max(saved[i][j], r - l);
                cur -= (s[l ++] - 'a' != i);
            }
        }
    }

    int q;
    cin >> q;

    while (q --) {
        int x;
        char c;
        cin >> x >> c;
        cout << saved[c - 'a'][x] << '\n';
    }

    return 0;
}