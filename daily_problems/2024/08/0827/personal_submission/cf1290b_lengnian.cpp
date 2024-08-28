#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using i128 = __int128;
using ull = unsigned long long;
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define pqi priority_queue<int> // 优先队列

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    auto solve = [&]()
    {
        string s;
        cin >> s;

        int n = int(s.size());

        vector pref(n + 1, vector<int>(26));
        for (int i = 0; i < n; i++)
        {
            pref[i + 1] = pref[i];
            pref[i + 1][s[i] - 'a']++;
        }

        int q;
        cin >> q;

        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;

            int cnt = 0;
            for (int j = 0; j < 26; j++)
            {
                cnt += pref[r][j] != pref[l - 1][j];
            }

            cout << (r == l || s[l - 1] != s[r - 1] || cnt > 2 ? "Yes\n" : "No\n");
        }
    };

    solve();
    return 0;
}
