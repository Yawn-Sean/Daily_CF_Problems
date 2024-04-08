/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=200010;

vector<array<int,2>> s[N];
vector<array<int,2>> ans[N];

void solve(){
    int n,x;
    cin>>n>>x;
    vector<array<int,3>> q(n);
    for(auto &[a,b,c]:q){
        cin>>a>>b>>c;
        int d=b-a+1;
        s[d].pb({a,c});
    }
    for(int i=0;i<N;i++) sort(all(s[i]));

    for(int i=0;i<N;i++){
        int la=-1,v=-1;
        for(auto [l,w]:s[i]){
            if(la==-1) la=l,v=w;
            else if(l==la) v=min(v,w);
            else{
                ans[i].pb({la,v});
                la=l,v=w;
            }
        }
        if(la!=-1) ans[i].pb({la,v});
        int m=ans[i].size();
        for(int j=m-2;j>=0;j--){
            ans[i][j][1]=min(ans[i][j][1],ans[i][j+1][1]);
        }
    }
    int res=2e10;
    for(auto [a,b,c]:q){
        int d=b-a+1;
        array<int,2> t={b+1,0};
        if(x-d>=0){
            auto it=lower_bound(all(ans[x-d]),t)-ans[x-d].begin();
            if(it<(int)ans[x-d].size()){
                res=min(res,c+ans[x-d][it][1]);
            }
        }
    }
    if(res==2e10) res=-1;
    cout<<res;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
