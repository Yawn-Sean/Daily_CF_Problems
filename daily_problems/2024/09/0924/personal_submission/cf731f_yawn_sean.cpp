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

    int n, M = 2e5;
    cin >> n;

    vector<int> nums(n), acc(M + 2, 0);

    for (auto &x: nums) {
        cin >> x;
        acc[x + 1] ++;
    }

    for (int i = 0; i < M + 1; i ++) {
        acc[i + 1] += acc[i];
    }

    vector<long long> ans(M + 1, 0);

    for (int i = 1; i <= M; i ++) {
        for (int j = 0; j <= M; j += i) {
            ans[i] += 1ll * j * (acc[min(M + 1, j + i)] - acc[j]);
        }
    }

    long long res = 0;
    for (auto &x: nums) res = max(res, ans[x]);
    cout << res;

    return 0;
}