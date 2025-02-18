#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
void solve()
{
int n, m, tot;
cin >> n >> m >> tot;
vector a(n), b(m);
for (int i = 0; i < n; i++)
{
cin >> a[i];
}
for (int i = 0; i < m; i++)
{
cin >> b[i];
}
sort(a.begin(), a.end());
sort(b.begin(), b.end());
int l = 0, r = min(n, m), mid;
while (l < r)
{
mid = l + (r - l + 1) / 2;
int need = 0;
int f = 1;
for (int i = 0; i < mid; i++)
{
need += max(b[i] - a[n - mid + i], 0ll);
}
if (need > tot)
{
f = 0;
}
if (f)
{
l = mid;
}
else
{
r = mid - 1;
}
}
int sum = 0,cost=0;
mid = l;
for (int i = 0; i < mid; i++)
{
cost+=b[i];
}
cout<<l<<" "<<max(cost-tot,0ll)<<"\n";
}
signed main()
{
ios::sync_with_stdio(false), cin.tie(0);
int t = 1;
// cin >> t;
while (t--)
{
solve();
}
}
