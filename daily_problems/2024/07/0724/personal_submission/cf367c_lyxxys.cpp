#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 100050, mod = 998244353, inf = 1e9;

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<array<int,2>> nums(m);
    for (auto &[x, y] : nums) cin >> x >> y;
    sort(nums.begin(), nums.end(), [&](array<int,2> &x, array<int,2> &y){
        return x[1] > y[1];
    });

    auto F = [&](int x)->ll{
        ll res = x*(x-1)/2;
        if (x%2==0) res += (x-2)/2;
        return res + 1;
    };
    ll res = 0;
    for (int i = 0; i < m; ++ i){
        if (F(i+1) > n) break;
        res += nums[i][1];
    }
    cout << res << "\n";
}
