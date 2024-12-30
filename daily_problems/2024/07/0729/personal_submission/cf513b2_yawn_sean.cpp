#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long k;
    cin >> n >> k;
    k --;

    vector<int> ans(n);
    int l = 0, r = n - 1;

    for (int i = 1; i < n; i ++)
        if (k >> (n - i - 1) & 1) ans[r --] = i;
        else ans[l ++] = i;
    
    ans[l] = n;
    for (auto &x: ans) cout << x << ' ';

    return 0;
}