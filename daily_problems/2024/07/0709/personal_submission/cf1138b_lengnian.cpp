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

    int n;
    cin >> n;
    vector<int> a, b, c;
    int t = 0;
    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '1' && s2[i] == '0')
        {
            a.pb(i + 1);
        }
        if (s1[i] == '0' && s2[i] == '1')
        {
            a.pb(i + 1);
        }
        if (s1[i] == '1' && s2[i] == '1')
        {
            b.pb(i + 1);
        }
        if (s1[i] == '0' && s2[i] == '0')
        {
            c.pb(i + 1);
        }
        if (s2[i] == '1')
        {
            t++;
        }
    }
    int flag = 0;
    int x = a.size(), y = b.size(), z = c.size();
    for (int i = 0; i <= y; i++)
    {
        int m = t - 2 * i;
        if (m >= 0 && n / 2 - i - m >= 0 && m <= x && n / 2 - i - m <= z)
        {
            x = m;
            y = i;
            z = n / 2 - i - m;
            flag = 1;
        }
    }

    if (flag)
    {
        for (int i = 0; i < x; i++)
        {
            cout << a[i] << " ";
        }
        for (int i = 0; i < y; i++)
        {
            cout << b[i] << " ";
        }
        for (int i = 0; i < z; i++)
        {
            cout << c[i] << " ";
        }
    }
    else
    {
        cout << "-1";
    }
    return 0;
}
