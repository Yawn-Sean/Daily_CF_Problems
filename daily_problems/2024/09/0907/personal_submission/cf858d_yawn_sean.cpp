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
    
    vector<string> strs(n);
    for (auto &s: strs) cin >> s;

    map<pair<int, int>, int> mp;
    for (int idx = 0; idx < n; idx ++) {
        for (int i = 0; i < 9; i ++) {
            int cur = 0;
            for (int j = i; j < 9; j ++) {
                cur = cur * 10 + strs[idx][j] - '0';
                if (mp.find({cur, j-i}) == mp.end()) mp[{cur, j-i}] = idx;
                else if (mp[{cur, j-i}] != idx) mp[{cur, j-i}] = -1;
            }
        }
    }

    for (int idx = 0; idx < n; idx ++) {
        int str_len = 10, start = 0;
        for (int i = 0; i < 9; i ++) {
            int cur = 0;
            for (int j = i; j < 9; j ++) {
                cur = cur * 10 + strs[idx][j] - '0';
                if (j - i < str_len && mp[{cur, j-i}] == idx) {
                    start = i;
                    str_len = j - i;
                }
            }
        }
        cout << strs[idx].substr(start, str_len + 1) << '\n';
    }
    return 0;
}