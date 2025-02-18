#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;
    if (a < b)
        cout << -1;
    else {
        cout << setprecision(12) << (a + b) / (2.*((a + b) / (2 * b))) << endl;
    }
    return 0;
}
