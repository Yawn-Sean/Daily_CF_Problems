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
const int N = 2e5 + 10, mod = 1e9 + 7;
int n, m, k, p;

PII a[N];
void solve()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;

    double ans = 0;
    for (int i = 2; i <= n; i++)
    {
        int l1 = a[i - 1].first, r1 = a[i - 1].second;
        int l2 = a[i].first, r2 = a[i].second;
        double p1 = 1.0 * (r1 / p - (l1 - 1) / p) / (r1 - l1 + 1), p2 = 1.0 * (r2 / p - (l2 - 1) / p) / (r2 - l2 + 1);
        double p = p1 * (1 - p2) + (1 - p1) * p2 + p1 * p2;
        ans += p * 2000;
    }
    int l1 = a[1].first, r1 = a[1].second;
    int l2 = a[n].first, r2 = a[n].second;
    double p1 = 1.0 * (r1 / p - (l1 - 1) / p) / (r1 - l1 + 1), p2 = 1.0 * (r2 / p - (l2 - 1) / p) / (r2 - l2 + 1);
    double p = p1 * (1 - p2) + (1 - p1) * p2 + p1 * p2;
    ans += p * 2000;

    cout << fixed << setprecision(8) << ans << '\n';
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
