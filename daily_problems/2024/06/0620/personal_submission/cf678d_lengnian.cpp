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

const i64 p = 1000000007;

int power(int a, i64 b, int p)
{
    int res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p)
    {
        if (b % 2)
        {
            res = 1LL * res * a % p;
        }
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    i64 A, B, n, x;
    cin >> A >> B >> n >> x;
    if (A == 1)
    {
        i64 res = (x + n % p * B) % p;
        cout << res;
    }
    else
    {
        i64 res = power(A, n, p) * x % p;
        res += (power(A, n, p) - 1) * power(A - 1, p - 2, p) % p * B;
        cout << (res % p + p) % p;
    }
    return 0;
}
