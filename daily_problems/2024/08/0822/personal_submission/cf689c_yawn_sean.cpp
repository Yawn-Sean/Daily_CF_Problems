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
    
    function<long long(long long)> check = [] (long long x) -> long long {
        long long ans = 0;
        for (int v = 2; x / v / v / v > 0; v ++)
            ans += x / v / v / v;
        return ans;
    };

    long long target;
    cin >> target;
    long long l = 1, r = target * 8;
    while (l <= r) {
        long long m = l + (r - l) / 2;
        if (check(m) >= target) r = m - 1;
        else l = m + 1;
    }
    cout << (check(l) == target ? l : -1);

    return 0;
}