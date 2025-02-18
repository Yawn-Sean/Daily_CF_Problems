#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> s(n, 0);

    function<int(void)> query = [&] () -> int {
        cout << '?' << ' ';
        for (auto &c: s) cout << c;
        cout << '\n';
        cout.flush();
        int ans;
        cin >> ans;
        return ans;
    };

    int x = query();
    s[n-1] = 1;
    int y = query();

    int pos0, pos1;
    if (x < y) {
        pos0 = n - 1;
        for (int i = 0; i < n; i ++) {
            s[i] = 1;
        }
        int benchmark = query();
        int l = 0, r = n - 2;
        while (l <= r) {
            int mid = (l + r) / 2;
            for (int i = 0; i < n; i ++)
                s[i] = (i <= mid ? 0 : 1);
            if (benchmark - query() == mid + 1) l = mid + 1;
            else r = mid - 1;
        }
        pos1 = l;
    }
    else {
        pos1 = n - 1;
        int benchmark = x;
        int l = 0, r = n - 2;
        while (l <= r) {
            int mid = (l + r) / 2;
            for (int i = 0; i < n; i ++)
                s[i] = (i <= mid ? 1 : 0);
            if (benchmark - query() == mid + 1) l = mid + 1;
            else r = mid - 1;
        }
        pos0 = l;
    }
    cout << '!' << ' ' << pos0 + 1 << ' ' << pos1 + 1 << '\n';
    cout.flush();

    return 0;
}