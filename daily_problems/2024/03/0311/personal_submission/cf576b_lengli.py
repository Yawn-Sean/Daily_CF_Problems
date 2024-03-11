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

vector<int> eg[N];
int p[N],sz[N];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void merge(int a,int b){
    a=find(a),b=find(b);
    if(a==b) return;
    p[a]=b;
    sz[b]+=sz[a];
}

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) p[i]=i,sz[i]=1;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        merge(i,x);
        eg[i].pb(x);
    }
    int flag=0,cnt=0,st=0,idx=-1;
    for(int i=1;i<=n;i++){
        if(find(i)!=i) continue;
        if(sz[i]==1){
            cout<<"YES"<<endl;
            for(int j=1;j<=n;j++){
                if(j!=i) cout<<j<<" "<<i<<endl;
            }
            return;
        }
        cnt+=(sz[i]%2);
        if(sz[i]==2) idx=i;
    }
    if(idx!=-1 and !cnt){
        int l=idx,r=eg[idx][0];
        vector<bool> st(n+1,0);
        st[l]=st[r]=1;
        cout<<"YES"<<endl;
        cout<<l<<" "<<r<<endl;
        vector<int> a,b;
        for(int j=1;j<=n;j++){
            int to=1,v=j;
            while(!st[v]){
                st[v]=1;
                if(to) a.pb(v);
                else b.pb(v);
                v=eg[v][0];to^=1;
            }
        }
        for(auto x:a) cout<<l<<" "<<x<<endl;
        for(auto x:b) cout<<r<<" "<<x<<endl;
    }else cout<<"NO"<<endl;

}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
