#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m,l;cin>>n>>m>>l;
    vector<int>a(l),g[n],ans(n),d[2];
    for(auto&i:a)cin>>i;
    for(int i=0,u,v;i<m;i++){
        cin>>u>>v;u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    d[0]=vector<int>(n,1e18);
    d[1]=vector<int>(n,1e18);
    queue<pair<int,int>>q;
    q.push({0,0});
    while(q.size()){
        auto [id,v]=q.front();q.pop();
        if(d[v%2][id]>v){
            d[v%2][id]=v;
            for(auto&i:g[id]){
                if(d[(v+1)%2][i]>(v+1)){
                    q.push({i,v+1});
                }
            }
        }
    }
    int mxodd=-1,mxeven=-1,sum=0;
    sort(a.begin(),a.end());
    for(auto&i:a)sum+=i;
    if(sum%2){
        mxodd=sum;
        for(int i=0;i<l;i++){
            if(a[i]%2){
                mxeven=mxodd-a[i];
                break;
            }
        }
    }
    else{
        mxeven=sum;
        for(int i=0;i<l;i++){
            if(a[i]%2){
                mxodd=mxeven-a[i];
                break;
            }
        }
    } 
    // cout<<mxodd<<" "<<mxeven<<'\n';
    for(int i=0;i<n;i++){
        // cout<<d[0][i]<<' '<<d[1][i]<<'\n';
        if(mxeven!=-1&&mxeven>=d[0][i]){
            ans[i]=1;
        }
        if(mxodd!=-1&&mxodd>=d[1][i]){
            ans[i]=1;
        }
    }
    for(auto&i:ans)cout<<i;cout<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;while(t--)
    solve();
}