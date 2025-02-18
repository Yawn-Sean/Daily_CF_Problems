/*
    Bonelight * V *
    20241010: CF Goodnight~
    No Coding, No Bug 
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define INF (int)2e14

void solve(){
   int a,b,h,w,n; cin >> a >> b >> h >> w >> n;
   vector<int> nums(n);
   for(auto &i:nums) cin >> i;
   sort(begin(nums),end(nums), greater<int>());

    n = min(n,34ll);
   
    auto div = [&](int x, int y){
        return (x + y - 1) / y;
    };
    auto bfs = [&](int xx, int yy){ // 待拓展倍数
        map<pii,int> mp;
        mp[{xx,yy}] = 0;

        for(int i = 0; i < n; i ++){
            vector<pii> o;
            for(auto &[x,y]:mp) o.push_back(x);
            for(auto &[x,y]:o){
                int nx = div(x,nums[i]), ny = div(y,nums[i]);
                if(!mp.count({nx,y})) mp[{nx,y}] = mp[{x,y}] + 1;
                if(!mp.count({x,ny})) mp[{x,ny}] = mp[{x,y}] + 1;
            }
        }
        return mp.count({1,1})? mp[{1,1}]:INF;
    };
    int ans = min(bfs(div(a, w), div(b,h)), bfs(div(a,h), div(b,w))); 
    cout << (ans == INF? -1:ans) << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    
    int T = 1;
    while(T --){
        solve();
    }
}
