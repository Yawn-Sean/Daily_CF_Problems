#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
void solve(){
	int n;cin>>n;
    vector<vector<int>> adj(n+7);
    for(int i=1;i<=n;i++){
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int x;cin>>x;
            adj[i].push_back(x);
        }
        sort(adj[i].begin(), adj[i].end());
    }
    int ans=0;
    for(int i=2;i<=n;i++){
        int l=adj[i].size();
        if(l==1)continue;
        int tans=ans;
        for(int j=0;j<l-1;j++){
                int down=adj[i][j],upper=adj[i][j+1];
                int a1=lower_bound(adj[i-1].begin(),adj[i-1].end(),upper)-lower_bound(adj[i-1].begin(),adj[i-1].end(),down);
                int a2=lower_bound(adj[(i%n)+1].begin(),adj[(i%n)+1].end(),upper)-lower_bound(adj[(i%n)+1].begin(),adj[(i%n)+1].end(),down);
                if(a1!=a2){
                    ans++;
                }
            }
    }
    int l=adj[1].size();
        int tans=0;
        for(int j=0;j<l-1;j++){
                int down=adj[1][j],upper=adj[1][j+1];
                int a1=lower_bound(adj[n].begin(),adj[n].end(),upper)-lower_bound(adj[n].begin(),adj[n].end(),down);
                int a2=lower_bound(adj[2].begin(),adj[2].end(),upper)-lower_bound(adj[2].begin(),adj[2].end(),down);
                if(a1!=a2){
                    // cout<<adj[1][j]<<" "<<adj[1][j+1]<<endl;
                    // cout<<a1<<" "<<a2<<endl;
                    ans++;
                }
            }
    cout<<ans<<endl;
}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
