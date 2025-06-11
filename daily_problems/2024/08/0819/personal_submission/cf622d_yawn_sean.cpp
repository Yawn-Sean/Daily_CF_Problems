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
    vector<int> ans(n * 2);
    for (int i = 0; i < n / 2; i ++) {
        ans[i] = i * 2 + 1;
        ans[n-1-i] = i * 2 + 1;
        ans[n+i] = (i + 1) * 2;
        ans[2*n-2-i] = (i + 1) * 2;
    }
    for (auto &x: ans) cout << (x ? x : n) << ' ';

    return 0;
}