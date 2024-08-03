/*------------------------------------------------------------------------------
 * @file    CF492D_PDOCW.CPP
 * @author  Pdocw
 * @date    2024/04/08 21:06:35
 * -----------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y, a;
    long long l, r, m;
    cin >> n >> x >> y;
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {

        cin >> a;
        l = 1, r = 1e18;
        while (l <= r)
        {
            m = (l + r) / 2;
            if (m / x + m / y >= a)
                r = m - 1;
            else
                l = m + 1;
        }
        if (l % x == 0)
            if (l % y == 0)
                ans.push_back("Both");
            else
                ans.push_back("Vova");
        else
            ans.push_back("Vanya");
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << "\n";
    return 0;
}
