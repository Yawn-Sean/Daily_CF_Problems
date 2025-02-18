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

int y[1005];
int a, a2, b, b2;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> y[i];

    auto check = [&](int op, int oq) -> bool
    {
        return 1LL * (y[oq] - y[op]) * a2 == 1LL * (oq - op) * a;
    };
    for (int i = 1; i <= 2; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            a = y[j] - y[i];
            a2 = j - i;
            b = i;
            b2 = 0;

            bool flag = true;
            for (int k = 1; k <= n && flag; k++)
            {
                if (check(k, b))
                    continue;
                if (b2 == 0)
                    b2 = k;
                else if (check(k, b2))
                    continue;
                else
                    flag = false;
            }
            if (flag && b2)
            {
                cout << "Yes" << "\n";
                return 0;
            }
        }
    }

    cout << "No" << "\n";
    return 0;
}
