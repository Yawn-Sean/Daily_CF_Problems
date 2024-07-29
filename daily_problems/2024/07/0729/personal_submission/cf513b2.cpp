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
    int m;
    cin >> n >> m;
    vector<int> a(n);

    int x = 0, y = n;

    for (int i = 1; i < n; i++)
    {
        if (m >> (n - i - 1) & 1)
        {
            a[x--] = i;
        }
        else
        {
            a[y++] = i;
        }
    }

    a[y] = n;
    for (int i = 0; i < n; i++)
    {

        cout << a[i] << " ";
    }

    cout << "\n";
    return 0;
}
