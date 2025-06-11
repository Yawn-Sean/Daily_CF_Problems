#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
void solve(){
	int n;cin>>n;vector<int> v;
    v.push_back(-1);
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        v.push_back(x);
    }
    int step=0;vector<int> ans(n+1,-1);
    ans[0]=0;ans[1]=0;
    queue<int> q;q.push(1);
    ans[0]=0;ans[1]=0;
    while(!q.empty())
    {
        int x=q.front();
        
        if(ans[v[x]]==-1)ans[v[x]]=ans[x]+1,q.push(v[x]);
        if(x<n&&ans[x+1]==-1){
            ans[x+1]=ans[x]+1;
            q.push(x+1);
            
        }
        if(x>1&&ans[x-1]==-1)ans[x-1]=ans[x]+1,q.push(x-1);
        q.pop();
        // cout<<x<<" "<<ans[x-1]<<' '<<ans[x]<<' '<<ans[x+1]<<endl;
    }
    for(int i=1;i<=n;i++)
    cout<<ans[i]<<" ";
}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
