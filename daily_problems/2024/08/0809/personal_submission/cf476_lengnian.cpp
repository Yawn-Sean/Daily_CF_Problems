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

int mod = 1e9 + 7;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int ans = 0;

    for (int i = 1; i < b; i++)
    {
        int sum = (1 + a) * a / 2;
        sum %= mod;
        int x = (a + b * sum);
        x %= mod;
        ans += i * x;
        ans %= mod;
    }

    cout << ans << "\n";
    return 0;
}
