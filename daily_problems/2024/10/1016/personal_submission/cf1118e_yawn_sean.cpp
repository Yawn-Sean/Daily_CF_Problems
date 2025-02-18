#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    if (k <= 1000 && n > k * (k - 1))
        cout << "NO";
    else {
        cout << "YES\n";
        for (int i = 1; i <= k; i ++) {
            for (int j = 1; j < i && n > 0; j ++) {
                cout << j << ' ' << i << '\n';
                n --;
                if (n) {
                    cout << i << ' ' << j << '\n';
                    n --;
                }
            }
        }
    }

    return 0;
}