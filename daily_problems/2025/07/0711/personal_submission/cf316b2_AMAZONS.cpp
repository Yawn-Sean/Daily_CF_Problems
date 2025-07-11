#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
vector<int> v,vis;
void solve(){
	int n,pos;cin>>n>>pos;vector<int> color(n+10);
    v.resize(n+1);vis.resize(n+1,0);vector<int>front(n+1,0);
    for(int i=1;i<=n;i++)
    {int x;cin>>x;if(x)v[x]=i,vis[i]=1;front[i]=x;}
    int col=0;int siz=0;
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        int tmp=i,cnt=0,flag=0;
        while(tmp){
            cnt++;
            if(tmp==pos){
                siz=cnt;
                flag=1;
                break;
            }
            tmp=v[tmp];
        }
        if(!flag)
        color[++col]=cnt;
    }
    vector<int> ans(1010,0);
    ans[0]=1;
    for(int i=1;i<=col;i++){
        // cout<<color[i]<<" ";
        for(int j=n;j>=color[i];j--){
            if(ans[j-color[i]])ans[j]=1;
        }
    }
    for(int i=0;i<=n;i++){
        if(ans[i])cout<<i+siz<<'\n';
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
