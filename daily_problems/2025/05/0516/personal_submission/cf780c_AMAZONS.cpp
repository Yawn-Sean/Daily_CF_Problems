#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
vector<int> grp[N];
vector<int> ans(N),vis(N);
int maxi=-1;
void dfs(int s,int a,int b){
    maxi=max(maxi,a);
    // cout<<s<<a<<b<<endl;
    int cur=1;ans[s]=a;vis[s]=1;
    for(auto& it:grp[s]){
        if(vis[it])continue;
        while(cur==a||cur==b){cur++;}
        ans[it]=cur;
        dfs(it,cur,a);
        cur++;
    }
    return ;
}
void solve(){
	int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        grp[x].push_back(y);
        grp[y].push_back(x);
    }
    dfs(1,1,0);
    cout<<maxi<<endl;
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
