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

    int a, b, mod;
    cin >> a >> b >> mod;
    for (int i = 0; i <= a && i < mod; i++)
        if ((mod - (long long)i * 1000000000 % mod) % mod > b)
        {
            std::cout << "1 " << std::setw(9) << std::setfill('0') << i << std::endl;
            return 0;
        }
    cout << 2 << "\n";
}
