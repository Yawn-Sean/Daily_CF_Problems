#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
vector<vector<char>> mp;
vector<vector<int>> vis,num;
map<int,int> cat;
int n,m;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void dfs(int x,int y,int label)
{
    // if(vis[x][y])return ;
    vis[x][y]=label;
    cat[label]++;
    for(int i=0;i<4;i++)
    {
        int tx=x+dx[i],ty=y+dy[i];
        if(tx<1||ty<1||tx>n||ty>m||vis[tx][ty]||mp[tx][ty]=='*')continue;
        dfs(tx,ty,label);
    }
}
void solve(){
	cin>>n>>m;
    mp.assign(n+7,vector<char>(m+7));
    vis.assign(n+7,vector<int>(m+7,0));
    num.assign(n+7,vector<int>(m+7,0));
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)cin>>mp[i][j];
    int label=1;
    // dfs(1,2,1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!vis[i][j]&&mp[i][j]!='*'){dfs(i,j,label);label++;}
        }
    }
    int look[label+7]={0},pos=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]=='*'){
                int cnt=0;
                for(int k=0;k<4;k++)
                {
                    int tx=i+dx[k],ty=j+dy[k];
                    if(tx<1||ty<1||tx>n||ty>m||mp[tx][ty]=='*')continue;
                    int cur_label=vis[tx][ty];
                    if(look[cur_label]==pos)continue;
                    else cnt=(cnt+cat[cur_label])%10,look[cur_label]=pos;
                    
                }
                pos++;
                cout<<(cnt+1)%10;
            }
            else{
                cout<<".";
            }
        }
        cout<<endl;
    }



}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
