/*
    Bonelight =^x^=
    20241117: 单枪匹马，无畏粉身碎骨
    我尝试过无数次了，但我知道，机会只会出现在其中的一两次
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define pii pair<int,int>
#define tiii tuple<int,int,int>  
#define INF 2e18
#define VC vector<int>
#define MAT vector<VC>
#define x first
#define y second

/*希望残酷的世界还能为我这样的蝼蚁留下一丝美好*/

void solve(){
    int n; cin >> n;
    vector<pii> a(n);
    for(auto &[x,y]:a) cin >> x >> y;

    double score = 0;
    int cur = 1;
    VC ans;
    unordered_map<int,int> mp;
    for(int i = 1; i <= min(20ll,n); i ++){
        mp.clear();
        for(auto [x,y]:a) mp[x] += min(y,i);
        vector<pii> tmp;
        for(auto [x,y]:mp) tmp.push_back({x,y});
        sort(begin(tmp), end(tmp), [&](auto x, auto y){return x.y > y.y;});
        int tot = 0;
        for(int j = 0; j < min((int)tmp.size(), i); j ++) tot += tmp[j].y;
        // tot / i > score / cur
        if(tot * cur > score * i){
            vector<int> nans(i);
            for(int j = 0; j < min((int)tmp.size(), i); j ++) nans[j] = tmp[j].x;
            score = tot, cur = min((int)tmp.size(), i);
            ans = nans;
        }
    }

    cout << cur << endl;
    for(int i = 0; i < cur; i ++){
        cout << ans[i] << ' ';
    }
    
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1; //cin >> T;
    while(T --){
        solve();
    } 
}
