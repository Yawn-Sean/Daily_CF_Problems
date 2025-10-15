/*
    Bonelight (=v=)
    20250111: 我是一个史官 
    == 拿着笔，想写点东西，以为是武器，能声张 正！E！ == 
    UID: cf1912d 
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 2e18

#define VC vector<int>
#define MAT vector<vector<int>>
#define VCii vector<pii>
#define MATii vector<vector<pii>>

#define For(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define all(_a) begin(_a), end(_a)
#define all1(_a) begin(_a)+1, end(_a)

#define x first
#define y second
#define ls (o << 1)
#define rs ((o << 1) + 1)
#define ULL unsigned long long

void solve(){
    int n; cin >> n;
    VC a(n+1),b(n+1);
    map<int,map<int,int>> mp;
    For(i,1,n) cin >> a[i], mp[a[i]][i]++;
    For(i,1,n) cin >> b[i], mp[b[i]][i]++;
    
    int m; cin >> m;
    VC num(n+1,1);
    For(i,2,n) num[i] = num[i-1] * i % m; 
    
    auto calc = [&](int x, int y){
        int res = 1;
        For(i,2,x){
            if(i % 2 == 0 && y > 0) {res = res * (i/2) % m; y --;}
            else res = res * i % m;
        }
        return res;
    };

    int ans = 1;
    for(auto idx = mp.begin(); idx != mp.end(); idx ++){
        auto key = idx->second;
        int sz = 0;
        int d = 0; 
        for(auto idx2 = key.begin(); idx2 != key.end(); idx2 ++){
            sz += idx2->second;
            if(idx2->second > 1) d ++;
        }
        ans = ans * calc(sz,d) % m;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif
    int T = 1; 
    while(T --) solve();
    return 0;
}
