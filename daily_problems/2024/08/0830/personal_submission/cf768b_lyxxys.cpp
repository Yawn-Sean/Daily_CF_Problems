#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n, l, r;
    cin >> n >> l >> r;
    map <ll, ll> mps;
    vector <ll> nums;
    ll cur = n;
    while (cur > 1){
        nums.push_back(cur);
        cur /= 2;
    }
    nums.push_back(cur);
    reverse(nums.begin(), nums.end());
    mps[nums[0]] = 1;
    for (ll i = 1, lst = 1; i < nums.size(); ++ i){
        lst = (mps[nums[i]] = 2*lst + 1);
    }

    function <int(ll,ll,ll)> dfs = [&](ll x, ll pl, ll pr){
        if (pl == pr){
            assert(x <= 1);
            return x==1 ? 1 : 0;
        }
        ll y = x/2, sz = mps[y];
        int res = 0;
        if (pl+sz-1 >= l) res += dfs(y, pl, pl+sz-1);
        if (x%2 && pl+sz >= l && pl+sz <= r) res += 1;
        if (pl+sz+1 <= r) res += dfs(y, pl+sz+1, pr);
        return res;
    };

    int res = dfs(n, 1, mps[n]);
    cout << res << "\n";
}
