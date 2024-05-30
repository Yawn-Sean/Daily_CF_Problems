#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << n << '\n';
        return 0;
    }
    
    string s, t;
    cin >> s >> t;

    long long ans = 0;
    int cur = 1;

    for (int i = 0; i < n; i ++)
        cur = min(k, cur * 2 - (s[i] == 'b') - (t[i] == 'a')), ans += cur;
    
    cout << ans << '\n';

    return 0;
}
