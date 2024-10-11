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

    int v0 = 0, v1023 = 1023;
    while (n --) {
        char op;
        int x;
        cin >> op >> x;
        if (op == '|') v0 |= x, v1023 |= x;
        else if (op == '&') v0 &= x, v1023 &= x;
        else v0 ^= x, v1023 ^= x;
    }
    cout << 2 << '\n';
    cout << "& " << (v0 ^ v1023) << '\n';
    cout << "^ " << v0;

    return 0;
}