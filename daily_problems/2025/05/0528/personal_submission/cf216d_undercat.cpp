#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    vector<int>g[n];
    for(int i=0,k;i<n;i++){
        cin>>k;
        for(int j=0,u;j<k;j++){
            cin>>u;
            g[i].push_back(u);
        }
        sort(g[i].begin(),g[i].end());
    }
    int res=0;
    for(int i=0;i<n;i++){
        int next=(i+1)%n;
        int pre=(i+n-1)%n;
        for(int j=0;j+1<g[i].size();j++){
            int cntpre=upper_bound(g[pre].begin(),g[pre].end(),g[i][j+1])-lower_bound(g[pre].begin(),g[pre].end(),g[i][j]);
            int cntnext=upper_bound(g[next].begin(),g[next].end(),g[i][j+1])-lower_bound(g[next].begin(),g[next].end(),g[i][j]);
            if(cntpre!=cntnext){
                // cout<<cntpre<<' '<<cntnext<<' '<<i<<' '<<j<<'\n';
                res++;
            }
        }
    }
    cout<<res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}