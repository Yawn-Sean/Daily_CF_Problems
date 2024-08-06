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

    long long k;
    cin >> k;
    k --;
    
    long long start = 1, digit = 1, cnt = 9;

    while (k >= digit * cnt) {
        k -= digit * cnt;
        start *= 10;
        digit += 1;
        cnt *= 10;
    }
    long long x = k / digit, y = k % digit;
    cout << to_string(start + x)[y];

    return 0;
}