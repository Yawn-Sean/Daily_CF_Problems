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

    int n, a, b, k;
    cin >> n >> a >> b >> k;

    string s;
    cin >> s;

    vector<int> ans;
    int cur = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] - '0') cur = 0;
        else {
            cur ++;
            if (cur == b) {
                ans.emplace_back(i);
                cur = 0;
            }
        }
    }

    for (int i = 0; i < a - 1; i ++)
        ans.pop_back();
    
    cout << ans.size() << '\n';
    for (auto &x: ans) cout << x + 1 << ' ';

    return 0;
}