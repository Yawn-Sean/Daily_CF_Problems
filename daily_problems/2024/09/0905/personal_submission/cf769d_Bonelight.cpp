#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define pii pair<int, int>

void solve1() 
{
    int n, k; cin >> n >> k;
    vector<int> a(n); for(auto &i:a) cin >> i;
    unordered_map<int,int> mp;
    for(auto i : a) mp[i] ++;

    auto cnt = [&](int x){
        int res = 0;
        while(x){
            res ++;
            x -= x & -x;
        }
        return res;
    };

    int ans = 0;
    for(auto [x1,y1]: mp){
        for(auto [x2,y2]:mp){
            if(cnt(x1 ^ x2) == k){
                if(x1 == x2) ans += (y1 - 1) * y2;
                else ans += y1 * y2;
            } 
        }
    }
    ans /= 2;
    cout << ans << endl;
}   

void solve2()
{
    int n, k; cin >> n >> k;
    vector<int> a(n); for(auto &i:a) cin >> i;
    unordered_map<int,int> mp;
    for(auto i : a) mp[i] ++;

    auto cnt = [&](int x){
        int res = 0;
        while(x){
            res ++;
            x -= x & -x;
        }
        return res;
    };

    
    int ans = 0;
    if(k == 0){
        for(int i = 0; i <= (1 << 14); i ++ ){
            ans += mp[i] * (mp[i] - 1) / 2;
        }
    } else{
        vector<int> val;
        for(int i = 0; i <= (1 << 14); i ++){
            if(cnt(i) == k) val.push_back(i);
        }

        for(int i = 0; i <= (1 << 14); i ++){
            for(auto v:val) ans += mp[i] * mp[i ^ v];
        }
        ans /= 2;
    }
    cout << ans << endl;
}   

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
        solve1();
}
