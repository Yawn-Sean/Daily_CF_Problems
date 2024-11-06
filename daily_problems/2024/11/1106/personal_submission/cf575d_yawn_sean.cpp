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

    cout << "2000\n";

    for (int i = 1; i <= 1000; i ++)
        cout << i << ' ' << 1 << ' ' << i << ' ' << 2 << '\n';
    
    for (int i = 1000; i >= 1; i --)
        cout << i << ' ' << 1 << ' ' << i << ' ' << 2 << '\n';

    return 0;
}