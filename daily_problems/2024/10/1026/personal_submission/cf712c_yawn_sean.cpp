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

    int x, y;
    cin >> x >> y;

    int a = y, b = y, cnt = 0;

    while (a < x) {
        b += a - 1;
        swap(a, b);
        cnt ++;
    }

    cout << cnt + 2;

    return 0;
}