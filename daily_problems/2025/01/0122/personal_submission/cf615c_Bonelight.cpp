/*
    Bonelight (=v=)
    20250111: 我是一个史官 
    == 拿着笔，想写点东西，以为是武器，能声张 正！E！ == 
    UID: cf615c_Bonelight.cpp
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
// #define endl '\n'
#define int long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
// #define INF 2e9
#define INF 2e18

#define VC vector<int>
#define MAT vector<vector<int>>
#define VCii vector<pii>
#define MATii vector<vector<pii>>

#define For(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define all(_a) begin(_a), end(_a)
#define all1(_a) (begin(_a) + 1), end(_a)
#define x first
#define y second 

void solve(){
    string a,b; cin >> a >> b;
    int n1 = a.size(), n2 = b.size();
    a = " " + a, b = " " + b;

    MAT dp1(n1 + 2, VC(n2 + 2)), dp2(n1 + 2, VC(n2 + 2)); //[i][j] a[i],b[j] 最长延展数量 
    
    Rof(i,n1,1)
    Rof(j,n2,1)
    if(a[i] == b[j]) dp1[i][j] = dp1[i + 1][j + 1] + 1;            
    
    For(i,1,n1)
    Rof(j,n2,1)
    if(a[i] == b[j]) dp2[i][j] = dp2[i - 1][j + 1] + 1;
        
    VCii ans;
    for(int i=1;i<=n2;){
        int l1=0,r2=0,t=i;
        For(k,1,n1) if(dp1[k][i] > dp1[l1][i]) l1 = k;
        For(k,1,n1) if(dp2[k][i] > dp2[r2][i]) r2 = k;

        if(dp1[l1][i] > dp2[r2][i]){
            ans.push_back({l1,l1 + dp1[l1][i] - 1});
            i += dp1[l1][i];
        }else{
            ans.push_back({r2,r2 - (dp2[r2][i] - 1)});
            i += dp2[r2][i];
        }
        if(t == i) return void(cout << -1 << endl); // 找不到的情况
    }

    cout << ans.size() << endl;
    for(auto [l,r]:ans) cout << l << ' ' << r << endl;
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
