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

void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int cnt[26]{};
    for (auto c : s)
    {
        cnt[c - 'a']++;
    }
    for (auto c : t)
    {
        cnt[c - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2 == 1)
        {
            cout << "No" << "\n";
            return;
        }
    }

    cout << "Yes" << "\n";
    vector<pii> a;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == t[i])
            continue;
        for (int j = i + 1; j < n; ++j)
        {
            if (s[i] == s[j])
            {
                a.emplace_back(j, i);
                swap(s[j], t[i]);
                break;
            }
            if (s[i] == t[j])
            {
                a.emplace_back(j, j);
                swap(s[j], t[j]);
                a.emplace_back(j, i);
                swap(s[j], t[i]);
                break;
            }
        }
    }

    cout << a.size() << "\n";
    for (auto s : a)
    {
        cout << s.fi + 1 << " " << s.se + 1 << "\n";
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
