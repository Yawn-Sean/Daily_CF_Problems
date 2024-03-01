//结论：竞赛图中只能从出度大的点走到出度小的点。
//枚举所有(i,j)对，按照入度差值大小排序，询问的时候要注意方向即可。

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

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
    vector<int> a(n+2);
    for(int i=1;i<=n;i++) cin>>a[i];
    auto query=[&](int u,int v){
        cout<<"? "<<u<<" "<<v<<endl;
        string s;
        cin>>s;
        return s=="Yes";
    };
    vector<array<int,2>> q;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) q.pb({i,j});
        }
    }

    sort(all(q),[&](auto l,auto r){
        return abs(a[l[0]]-a[l[1]])>abs(a[r[0]]-a[r[1]]);
    });
    for(auto [l,r]:q){
        if(a[l]<a[r]) swap(l,r);
        if(query(l,r)){
            cout<<"! "<<l<<" "<<r<<endl;
            return;
        }
    }
    cout<<"! 0 0"<<endl;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
