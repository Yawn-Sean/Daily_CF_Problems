#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e6 + 10, mod = 1e9 + 7;
int n, m, k;

int p[N];
int pre_xor[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        pre_xor[i] = pre_xor[i - 1] ^ i;
    int v = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        v ^= p[i];
    }

    for (int i = 2; i <= n; i++)
    {
        int up = i - 1;
        int d = n / i, r = n % i;
        if (d % 2 == 1)
        {
            v ^= pre_xor[up];
        }
        v ^= pre_xor[r];
    }
    cout << v << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }

    return 0;
}
