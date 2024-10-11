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
    int n, q;
    cin >> n >> q;
    while (q--)
    {
        int u;
        cin >> u;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            int pos = u & -u;
            if (s[i] == 'L')
            {
                if (u & 1)
                    continue;
                u ^= pos;
                u ^= pos >> 1;
            }
            else if (s[i] == 'R')
            {
                if (u & 1)
                    continue;
                u ^= pos >> 1;
            }
            else if (s[i] == 'U')
            {
                if ((u << 1) == (n + 1))
                    continue;
                u |= pos << 1;
                u ^= pos;
            }
        }

        cout << u << "\n";
    }
    return 0;
}
