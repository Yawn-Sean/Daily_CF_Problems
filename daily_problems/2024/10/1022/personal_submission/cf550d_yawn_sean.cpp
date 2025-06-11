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

    int k;
    cin >> k;

    if (k & 1) {
        cout << "YES\n";
        cout << 4 * k - 2 << ' ' << (2 * k - 1) * k << '\n';

        for (int i = 0; i < k - 1; i ++) {
            for (int j = 0; j < k - 1; j ++) {
                cout << i + 1 << ' ' << j + k << '\n';
                cout << i + 2 * k - 1 << ' ' << j + 3 * k - 2 << '\n';
            }

            if (i & 1) {
                cout << i << ' ' << i + 1 << '\n';
                cout << i + 2 * k - 2 << ' ' << i + 2 * k - 1 << '\n';
            }

            cout << i + k << ' ' << 4 * k - 3 << '\n';
            cout << i + 3 * k - 2 << ' ' << 4 * k - 2 << '\n';
        }

        cout << 4 * k - 3 << ' ' << 4 * k - 2 << '\n';
    }
    else cout << "NO";

    return 0;
}