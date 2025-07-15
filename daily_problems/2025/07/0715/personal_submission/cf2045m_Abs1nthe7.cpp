#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//如何处理反射？//n,m较小，可以直接暴力模拟一遍
//对于'/'-(0,1)-(-1,0)  (1,0)-(0,-1)    
//对于'\'-(0,1)-(1,0)   (0,-1)-(-1,0)
void sol()
{
   int n,m;cin>>n>>m;
   vector<string>grid(n);
   for(auto &s:grid)cin>>s;
   vector<pair<int,int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};//4个方向
   
   int res=0;
   //要走遍所有的镜子
   for(int i=0;i<n;++i)
     for(int j=0;j<m;++j)
     {
        if(grid[i][j]!='.')res++;
     }
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<pair<int,int>>ans;

    for(int i=0;i<m;++i)
    {
      {
        int x=0,y=i,dir=1;
        while(x>=0&&x<n&&y>=0&&y<m)
        {
            if(grid[x][y]!='.')//反射
            {
               vis[x][y]=1;
               dir^=(grid[x][y]=='\\'?1:3);
            }
            auto [dx,dy]=dirs[dir];
            x+=dx;y+=dy;
        }
        int c=0;
        for(int i=0;i<n;++i)
          for(int j=0;j<m;++j)
          {
            c+=vis[i][j];
            vis[i][j]=0;
          }
        if(c==res)ans.emplace_back(1,i);
      }
      {
         int x=n-1,y=i,dir=3;
         while(x>=0&&x<n&&y>=0&&y<m)
         {
            if(grid[x][y]!='.')//反射
            {
               vis[x][y]=1;
               dir^=(grid[x][y]=='\\'?1:3);
            }
            auto [dx,dy]=dirs[dir];
            x+=dx;y+=dy;
         }
        int c=0;
        for(int i=0;i<n;++i)
          for(int j=0;j<m;++j)
          {
            c+=vis[i][j];
            vis[i][j]=0;
          }
        if(c==res)ans.emplace_back(3,i);
      }
    }
    for(int i=0;i<n;++i)
    {
        {
            int x=i,y=0,dir=0;
            while(x>=0&&x<n&&y>=0&&y<m)
           {
            if(grid[x][y]!='.')//反射
            {
               vis[x][y]=1;
               dir^=(grid[x][y]=='\\'?1:3);
            }
            auto [dx,dy]=dirs[dir];
            x+=dx;y+=dy;
           }
         int c=0;
        for(int i=0;i<n;++i)
          for(int j=0;j<m;++j)
          {
            c+=vis[i][j];
            vis[i][j]=0;
          }
        if(c==res)ans.emplace_back(0,i);
        }
        {
            int x=i,y=m-1,dir=2;
            while(x>=0&&x<n&&y>=0&&y<m)
           {
            if(grid[x][y]!='.')//反射
            {
               vis[x][y]=1;
               dir^=(grid[x][y]=='\\'?1:3);
            }
            auto [dx,dy]=dirs[dir];
            x+=dx;y+=dy;
           }
         int c=0;
        for(int i=0;i<n;++i)
          for(int j=0;j<m;++j)
          {
            c+=vis[i][j];
            vis[i][j]=0;
          }
        if(c==res)ans.emplace_back(2,i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto&[x,y]:ans)
    {
        if(x==0)cout<<'W'<<y+1<<' ';
        else if(x==1)cout<<'N'<<y+1<<' ';
        else if(x==2)cout<<'E'<<y+1<<' ';
        else cout<<'S'<<y+1<<' ';
    }
    cout<<endl;
}
signed main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--)sol();
    return 0;
}
