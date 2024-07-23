#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int e[N],ne[N],h[N],idx,dist[3][N],g[N][N];
queue<int>q;
int n,m,s,t;
void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void bfs(int u,int x)
{
    dist[u][x]=0;
    q.push(x);
    while(q.size())
    {
        auto it=q.front();
        q.pop();
        for(int i=h[it];~i;i=ne[i]){
            int j=e[i];
            if(dist[u][j]==-1){
                dist[u][j]=dist[u][it]+1;
                q.push(j);
            }
        } 
    }
}
int main()
{
    cin>>n>>m>>s>>t;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        add(a,b),add(b,a);
        g[a][b]=g[b][a]=1;
    }
    memset(dist,-1,sizeof dist);
    for(int i=1;i<=2;i++){
        if(i==1)bfs(i,s);
        else bfs(i,t);
    }
    int k=dist[1][t],ans=0;
    //cout<<k<<' ';
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            if(i==j||g[i][j]==1)continue;
            if(k<=dist[1][i]+dist[2][j]+1&&(k<=dist[2][i]+dist[1][j]+1))ans++;
            //if(k<=dist[2][i]+dist[1][j]+1)ans++;
        }
    cout<<ans<<'\n';
    return 0;
}
