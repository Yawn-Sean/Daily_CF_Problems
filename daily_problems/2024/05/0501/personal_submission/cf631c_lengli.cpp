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
    int n,m;
    cin>>n>>m;
    vector<int> a(n+2);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<array<int,2>> q;

    priority_queue<array<int,2>> ma;
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> mi;
    vector<int> st(n+1,0);
    for(int i=1;i<=m;i++){
        int op,x;
        cin>>op>>x;
        while(q.size() and x>=q.back()[1]) q.pop_back();
        q.pb({op,x});
    }
    for(int i=1;i<=q[0][1];i++) {
        ma.push({a[i],i}),mi.push({a[i],i});
    }

    auto get1=[&](){
        while(ma.size() and st[ma.top()[1]]) ma.pop();
        st[ma.top()[1]]=1;
        return ma.top()[0];
    };
    auto get2=[&](){
        while(mi.size() and st[mi.top()[1]]) mi.pop();
        st[mi.top()[1]]=1;
        return mi.top()[0];
    };

    vector<int> res(n+1);
    for(int i=0;i<q.size()-1;i++){
        int l=q[i+1][1]+1,r=q[i][1];
        if(q[i][0]==1){
            for(int j=r;j>=l;j--) res[j]=get1();
        }else{
            for(int j=r;j>=l;j--) res[j]=get2();
        }
        
    }

    if(q.back()[0]==1){
        for(int j=1;j<=q.back()[1];j++) res[j]=get2();
    }else{
        for(int j=1;j<=q.back()[1];j++) res[j]=get1();
    }
    for(int j=q[0][1]+1;j<=n;j++) res[j]=a[j];
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";

}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
