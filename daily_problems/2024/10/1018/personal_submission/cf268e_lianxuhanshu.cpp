#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 50010, mod = 1e9 + 7;
int n, m, k;

struct Node
{
    int l, p;
} a[N];
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].l >> a[i].p;
    }

    sort(a, a + n, [&](Node A, Node B)
         { return A.l * A.p * (100 - B.p) > B.l * B.p * (100 - A.p); });

    double time = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i].l + (100 - a[i].p) / 100.0 * time;
        time += 1.0 * a[i].p * a[i].l / 100.0;
    }
    cout << fixed << setprecision(9) << 1.0 * ans << '\n';
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
