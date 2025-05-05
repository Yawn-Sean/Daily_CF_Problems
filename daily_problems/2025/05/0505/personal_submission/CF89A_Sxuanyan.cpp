#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n + 1, 0);
    long long val = 1e18;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i & 1)
            val = min(val, a[i]);
    }                       
    if (!(n & 1))
        cout << 0 << endl;
    else
        cout << min(val, 1ll * m / (n / 2 + 1) * k) << endl;
}
