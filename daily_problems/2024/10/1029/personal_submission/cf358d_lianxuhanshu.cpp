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
const int N = 3010, mod = 1e9 + 7;
int n, m, k;

int a[N], b[N], c[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    int f0 = a[1], f1 = b[1];
    for (int i = 2; i <= n; i++)
    {
        int temp = max(f0 + b[i], f1 + a[i]);
        f1 = max(f0 + c[i], f1 + b[i]);
        f0 = temp;
    }
    cout << f0 << '\n';
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
