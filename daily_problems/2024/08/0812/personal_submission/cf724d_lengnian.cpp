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

    int m;
    cin >> m;

    string s;
    cin >> s;

    int n = s.length();
    string ans;
    for (int c = 'a'; c <= 'z'; c++)
    {
        int j = -1;
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] <= c)
            {
                if (i - j > m)
                {
                    ok = false;
                }
                j = i;
            }
        }

        if (n - j > m)
        {
            ok = false;
        }
        if (!ok)
        {
            for (int i = 0; i < n; i++)
            {
                if (s[i] == c)
                {
                    ans += c;
                }
            }

            continue;
        }

        j = -1;
        int k = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] < c)
            {
                j = i;
            }
            else if (s[i] == c)
            {
                k = i;
            }
            if (i - j >= m)
            {
                j = k;
                ans += c;
            }
        }

        break;
    }

    cout << ans << "\n";
    return 0;
}
