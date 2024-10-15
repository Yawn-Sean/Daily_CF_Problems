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

    long long n, k;
    cin >> n >> k;

    for (long long i = 1; i <= k; i ++) {
        if (n % i != i - 1) {
            return cout << "No", 0;
        }
    }
    cout << "Yes";

    return 0;
}