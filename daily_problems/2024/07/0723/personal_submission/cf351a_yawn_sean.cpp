#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int tot = 0, cnt = 0, num;

    for (int i = 0; i < n * 2; i ++) {
        string s;
        cin >> s;
        num = 0;
        for (int j = s.size() - 3; j < s.size(); j ++)
            num = num * 10 + (s[j] - '0');
        tot += num;
        if (!num) cnt ++;
    }

    int ans = 2000 * n;

    for (int i = max(n - cnt, 0); i <= min(2 * n - cnt, n); i ++)
        ans = min(ans, abs(i * 1000 - tot));
    
    cout << ans / 1000 << '.';
    ans %= 1000;
    cout << ans / 100 << ans / 10 % 10 << ans % 10;

    return 0;
}