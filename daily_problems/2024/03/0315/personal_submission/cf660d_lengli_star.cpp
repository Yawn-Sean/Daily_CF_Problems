//这里给一种相当暴力的做法
//首先n<=2000，所以枚举所有线段，然后按长度分组。
//接下来枚举所有长度，找到斜率相同的之后，C(n,2)即可。
//但是要注意是平行四边形，所以每个会被计算2次，最后除以2即可。

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

const int N=100010;

void solve(){
    int n;
    cin>>n;
    vector<array<int,2>> a(n);
    for(auto &[x,y]:a) cin>>x>>y;
    map<int,vector<array<int,2>>> q;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int d=(a[j][0]-a[i][0])*(a[j][0]-a[i][0])+(a[j][1]-a[i][1])*(a[j][1]-a[i][1]);
            array<int,2> k={a[j][1]-a[i][1],a[j][0]-a[i][0]};
            q[d].pb(k);
        }
    }
    int res=0;
    for(auto [c,v]:q){
        int m=v.size();
        vector<int> st(m,0);
        for(int i=0;i<m;i++){
            if(st[i]) continue;
            st[i]=1;
            int cnt=1;
            auto x=v[i][0],y=v[i][1];
            for(int j=i+1;j<m;j++){
                if(st[j]) continue;
                if(x*v[j][1]==y*v[j][0]){
                    st[j]=1;
                    cnt++;
                }
            }
            res+=(cnt-1)*cnt/2;
        }
    }
    cout<<res/2;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
