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

    int n;
    cin >> n;

    vector<int> ls(n), ps(n);
    for (int i = 0; i < n; i ++) 
        cin >> ls[i] >> ps[i];

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {return ls[a] * ps[a] * (100 - ps[b]) > ls[b] * ps[b] * (100 - ps[a]);});

    long long ans = 0, cur = 0;
    for (auto &i: order) {
        ans += cur * (100 - ps[i]) + 10000ll * ls[i];
        cur += ls[i] * ps[i];
    }

    cout << setprecision(20) << (long double)1.0 * ans / 10000;

    return 0;
}