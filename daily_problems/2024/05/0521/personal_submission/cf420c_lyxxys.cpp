#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9, mod = 998244353, N = 100060;
map <array<int,2>, int> mp;

void solve(){
    int n, p;
    cin >> n >> p;
    auto comb = [](int b)->ll {
        return 1ll*b*(b-1)/2;
    };
    vector <int> cnt(n+1);
    for (int i = 0, x,y; i < n; ++ i){
        cin >> x >> y;
        if (y < x) swap(x, y);
        ++ cnt[x];
        ++ cnt[y];
        ++ mp[{x, y}];
    }
    ll res = 0;
    for (auto &it : mp){
        auto x = it.first;
        int y = it.second;
        if (cnt[x[0]] + cnt[x[1]] >= p && cnt[x[0]]+cnt[x[1]]-y < p) -- res;
    }
    sort(cnt.begin()+1, cnt.end(), greater<int>()), cnt[0] = INF;
    auto bsearch = [&](int x)->int{
        int l = 0, r = n;
        while (l < r){
            int mid = l+r+1 >> 1;
            if (cnt[mid] >= x) l = mid;
            else r = mid-1;
        }
        return l;
    };
    for (int i = n; i >= 1; -- i){
        int j = bsearch(p-cnt[i]);
        if (j >= i)  j = i-1;
        res += j;
    }
    if (res < 0) res = 0;
    cout << res << "\n";
}
