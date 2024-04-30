/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
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
    vector<int> q;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x<0) q.pb(i);
    }
    if(q.size()>k){
        cout<<-1<<endl;
        return;
    }
    int res=q.size()*2;
    if(q.size() and q.back()==n) res--;
    vector<array<int,2>> d;
    int j=1;
    for(int i=0;i<q.size();i++){
        if(q[i]>j) d.pb({q[i]-j,j==1 ? 0 : 2});
        else if(q[i]==j and j!=1) d.pb({0,2});
        j=q[i]+1;
    }
    if(j<=n) d.pb({n-j+1,1});
    sort(all(d),[&](auto l,auto r){
        if(l[1]!=r[1]) return l[1]>r[1];
        return l[0]<r[0];
    });
    k-=q.size();
    for(auto [len,v]:d){
        if(k>=len) k-=len,res-=v;
    }
    cout<<max(res,0);

}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
