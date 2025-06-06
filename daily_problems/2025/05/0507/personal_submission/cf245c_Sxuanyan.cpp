/*
因为这题是拿x 2*x 2*x+1 所以 如果n为偶数如 1 2 3 4
那么4位置不可能被拿走 1 2 3 4 5 就可以刚好存在两组
然后就是从后往前拿（这里是贪心的主要过程） 
如果i是奇数且a[i]>0那就i-1 i （i-1）/2的地方减少
否则如果为偶数就是i i+1 i/2 的地方减少
因为 i为偶数时（i-1）/2不存在
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n < 3 || !(n & 1))
    {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        while (a[i] > 0)
        {
            if (i & 1)
            {
                a[i]--;
                a[i - 1]--;
                a[(i - 1) >> 1]--;
            }
            else
            {
                a[i]--;
                a[i + 1]--;
                a[i >> 1]--;
            }
            ans++;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
