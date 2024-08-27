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

    string s;
    cin >> s;

    int n = s.size();
    vector<vector<int>> pref(26, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < 26; j ++)
            pref[j][i+1] = pref[j][i];
        pref[s[i] - 'a'][i+1] ++;
    }

    int q;
    cin >> q;

    while (q --) {
        int l, r;
        cin >> l >> r;
        l --, r --;
        int c = 0;
        for (int i = 0; i < 26; i ++)
            c += (pref[i][r+1] - pref[i][l] > 0);
        cout << (l != r && c <= 2 && s[l] == s[r] ? "No\n" : "Yes\n");
    }

    return 0;
}