#include<bits/stdc++.h>
using namespace std;
const int N =1007;
const int mod=1e9+7;
typedef long long ll;
pair<int,int> st,ed;
int vis[N][N][4];
int n,m;
vector<vector<char>> mp;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int flag=0;
void dfs(pair<int,int> cur,int cnt,int way)
{
    if(cnt>2||flag==1)return ;
    if(cur==ed){cout<<"YES"<<endl;flag=1;return ;}
    int cx=cur.first,cy=cur.second;
    for(int i=0;i<4;i++)
    {
        int tx=dx[i]+cx,ty=dy[i]+cy;
        if(tx>n||ty>m||tx<=0||ty<=0)continue;
        if(mp[tx][ty]=='*')continue;
        int ncnt=cnt+(way!=i);
        if(ncnt>2)continue;
        // if(vis[tx][ty][i]!=-1)continue;
        if(ncnt<vis[tx][ty][i])
        vis[tx][ty][i]=ncnt;
        else continue;
        pair<int,int> np=make_pair(tx,ty);
        dfs(np,ncnt,i);
        
    }
}
void solve(){
	cin>>n>>m;
    for(int i = 0; i <= n; ++i)
    for(int j = 0; j <= m; ++j)
        for(int d = 0; d < 4; ++d)
            vis[i][j][d] = INT_MAX;
    mp.assign(n+10,vector<char> (m+10));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
            if(mp[i][j]=='S')st=make_pair(i,j);
            if(mp[i][j]=='T')ed=make_pair(i,j);
        }
    }
    for (int i = 0; i < 4; i++) {
        // memset(vis,-1,sizeof vis);
        vis[st.first][st.second][i]=0;
        dfs(st,0,i);
    }
    if(!flag)cout<<"NO"<<endl;

}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
