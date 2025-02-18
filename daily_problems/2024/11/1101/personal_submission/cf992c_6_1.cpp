#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7;

int quik_power(int base, int power, int p)
{
    int result = 1;
    while (power > 0)
    {
        if (power & 1)
            result = result * base % p;

        base = base * base % p;

        power >>= 1;
    }

    return result % p;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int c = quik_power(2, k, mod);
    if (n == 0)
        cout << 0 << endl;
    else
        cout << (2 * c * (n % mod) % mod - (c - 1) + mod) % mod << endl;
}
signed main()
{
    int tt = 1;

    while (tt--)
    {
        solve();
    }
}
