#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
#define INT_MAX 1e9+7
vector<pair<int,int>> edge[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
vector<bool> vis(N,0);
vector<int> d1(N,INT_MAX),d2(N,INT_MAX);
vector<int> far(N,-1);
void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        edge[u].push_back({w,v});
        edge[v].push_back({w,u});
    }
    //第一段从1到n的最短路
    pq.push({0,1});d1[1]=0;
    while(!pq.empty())
    {
        auto [a,b]=pq.top();pq.pop();//a代表当前长度，b代表当前点
        // if(vis[b])continue;
        // vis[b]=1;换种方法去重一样的
        if(d1[b]==a){
            for(auto [len,pot]:edge[b])
            {
                if(d1[pot]>d1[b]+len){
                    d1[pot]=d1[b]+len;
                    pq.push({d1[pot],pot});
                    far[pot]=b;
                }
            }
        }
    } 
    int cur=n;
    vis[cur]=1;
    while(far[cur]!=-1)
    {
        cur=far[cur];
        vis[cur]=1;
    }
    //第二段从n到1的最短里
    pq.push({0,n});d2[n]=0;
    while(!pq.empty())
    {
        auto [a,b]=pq.top();pq.pop();//a代表当前长度，b代表当前点
        // if(vis[b])continue;
        // vis[b]=1;换种方法去重一样的
        if(d2[b]==a){
            for(auto [len,pot]:edge[b])
            {
                if(d2[pot]>d2[b]+len){
                    d2[pot]=d2[b]+len;
                    pq.push({d2[pot],pot});
                    far[pot]=b;
                }
            }
        }
    }
    int ans=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        for(auto [x,y] : edge[i])
        {
            if(vis[i]&&vis[y]&&(far[i]==y||far[y]==i))continue;
            ans=min(ans,d1[i]+d2[y]+x);
        }
    }
    // cout<<ans<<endl;
    cout<<(ans==INT_MAX ? -1:ans+d1[n]);

}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
