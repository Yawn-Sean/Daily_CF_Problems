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

const int N = 10010;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[N]{};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    int cnt[N]{};
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            cnt[a[j] - a[i]]++;
        }
    }
    int b[N]{};

    for (int i = 10001; i >= 0; i--)
    {
        b[i] = b[i + 1] + cnt[i];
    }
    int res = 0;
    for (int i = 1; i < 5000; i++)
    {
        for (int j = 1; j < 5000; j++)
        {
            res += (long long)cnt[i] * cnt[j] * b[i + j + 1];
        }
    }

    int x = n * (n - 1) / 2;

    cout << fixed << setprecision(10) << 1. * res / x / x / x << "\n";
    return 0;
}
