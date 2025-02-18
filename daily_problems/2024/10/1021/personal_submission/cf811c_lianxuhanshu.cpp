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
const int N = 5010, mod = 1e9 + 7;
int n, m, k;

int a[N];
int posl[N], posr[N];
int f[N];
int xor_v[N][N];
int cnt[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 5000; j++)
            cnt[j] = 0;
        xor_v[i][i] = a[i];
        cnt[a[i]]++;
        for (int j = i + 1; j <= n; j++)
        {
            xor_v[i][j] = xor_v[i][j - 1];
            cnt[a[j]]++;
            if (cnt[a[j]] == 1)
                xor_v[i][j] ^= a[j];
        }
    }

    for (int i = 0; i <= 5000; i++)
    {
        posl[i] = -1;
        posr[i] = -1;
    }
    for (int i = 1; i <= n; i++)
        if (posl[a[i]] == -1)
            posl[a[i]] = i;
    for (int i = n; i >= 1; i--)
        if (posr[a[i]] == -1)
            posr[a[i]] = i;

    for (int i = 1; i <= n; i++)
    {
        int pos = i;
        for (int j = i; j >= 1; j--)
        {
            if (posr[a[j]] > i)
                break;
            pos = min(pos, posl[a[j]]);
            if (j > pos)
                continue;
            f[i] = max(f[i], f[j - 1] + xor_v[j][i]);
        }
        f[i] = max(f[i], f[i - 1]);
    }
    cout << f[n] << '\n';
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
