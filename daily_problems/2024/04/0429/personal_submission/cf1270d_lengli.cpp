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
    int n,k;
    cin>>n>>k;

    auto query=[&](int x)->array<int,2>{
        cout<<"? ";
        for(int i=1;i<=k+1;i++){
            if(i==x) continue;
            else cout<<i<<" ";
        }
        cout<<endl;
        int c,v;
        cin>>c>>v;
        return {c,v};
    };
    map<int,int> q;
    int ma=0;
    for(int i=1;i<=k+1;i++){
        auto [c,v]=query(i);
        q[v]++;
        ma=max(ma,v);
    }
    cout<<"! "<<q[ma]<<endl;

}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
