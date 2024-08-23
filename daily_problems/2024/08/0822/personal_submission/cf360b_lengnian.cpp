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

const int N = 2000;
int n, m;
int f[N], a[N];
bool check(i64 mid)
{
   
    for (int i = 0; i < n; i++)
        f[i] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (mid * (i - j) >= abs(a[i] - a[j]))
                f[i] = max(f[i], f[j] + 1);
        
        
    for (int i = 0; i < n; i++)
        if (f[i] >= m)
            return true;
            
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    m = n - m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = -1, r = 2e9 + 1;
    while (r - l > 1)
    {
        int mid = (r + l) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }

    cout << r << "\n";
    return 0;
}
