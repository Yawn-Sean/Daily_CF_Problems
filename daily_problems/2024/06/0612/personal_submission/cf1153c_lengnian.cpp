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
    string s;
    cin >> n >> s;

    if (n % 2 == 1 || s.front() == ')' || s.back() == '(')
    {
        cout << ":(" << "\n";
        return;
    }
    s.front() = '(';
    s.back() = ')';
    int l = n / 2 - 1, r = n / 2 - 1;
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] == '(')
        {
            l--;
        }
        else if (s[i] == ')')
        {
            r--;
        }
    }
    if (l < 0 || r > 0)
    {
        cout << ":(" << "\n";
        return;
    }

    int res = 0;
    for (int i = 1, j = 0; i < n - 1; i++)
    {
        if (s[i] == '?')
        {
            if (j < l)
            {
                s[i] = '(';
            }
            else
                s[i] = ')';

            j++;
        }

        if (s[i] == '(')
        {
            res++;
        }
        else
        {
            if (res == 0)
            {
                cout << ":(" << "\n";
                return;
            }

            res--;
        }
    }

    cout << s << "\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    t = 1;
    while (t--)
        solve();

    return 0;
}
