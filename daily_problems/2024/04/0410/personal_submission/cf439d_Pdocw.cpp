#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m, greater<int>());
    long long ans = 0;
    for (int i = 0; i < min(n, m); i++)
        ans += max(0, b[i] - a[i]);
    cout << ans;
    return 0;
}
