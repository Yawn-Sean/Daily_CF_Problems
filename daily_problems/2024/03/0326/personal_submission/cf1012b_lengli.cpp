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

const int N=400010;

int n,m,q;
int p[N];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void merge(int a,int b){
    a=find(a),b=find(b+n);
    if(a==b) return;
    p[a]=b;
}

void solve(){
    cin>>n>>m>>q;
    for(int i=0;i<N;i++) p[i]=i;
    for(int i=1;i<=q;i++){
        int a,b;
        cin>>a>>b;
        merge(a,b);
    }
    int res=0;
    for(int i=1;i<=n+m;i++){
        if(p[i]==i) res++;
    }
    cout<<res-1;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
