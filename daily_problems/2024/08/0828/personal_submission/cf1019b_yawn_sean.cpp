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

    auto query = [&] (int x) -> int {
        int v1, v2;
        cout << "? " << x << '\n';
        cout.flush();
        cin >> v1;
        cout << "? " << x + n / 2 << '\n';
        cout.flush();
        cin >> v2;
        return v1 > v2 ? 1 : (v1 == v2 ? 0 : -1);
    };

    auto answer = [&] (int x) {
        cout << "! " << x << '\n';
    };

    if (n & 2)
        return answer(-1), 0;
    
    int l = 1, r = n / 2, target = query(1);
    if (target == 0) answer(1);
    else {
        while (l <= r) {
            int m = (l + r) / 2, v = query(m);
            if (v == 0)
                return answer(m), 0;
            if (v * target > 0) l = m + 1;
            else r = m - 1;
        }
        answer(l);
    }

    return 0;
}