/*
 * @Author: BlaCat
 */
#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::string> a(n);
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
    int dx[]={1,0,0,-1};
    int dy[]={0,1,-1,0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='W'){
                continue;
            }
            int vis[n][m][4];
            int vis1[n][m];
            for(int i1=0;i1<n;i1++){
                for(int j1=0;j1<m;j1++){
                    vis[i1][j1][0]=vis[i1][j1][1]=vis[i1][j1][2]=vis[i1][j1][3]=3;
                    vis1[i1][j1]=-1;
                }
            }
            std::queue<std::array<int,4>> q;
            q.push({i,j,0,0});
            q.push({i,j,0,1});
            q.push({i,j,0,2});
            q.push({i,j,0,3});
            while(!q.empty()){
                auto [x,y,cnt,f]=q.front();
                // std::cerr<<x<<" "<<y<<" "<<cnt<<" "<<f<<endl;
                vis[x][y][f]=std::min(vis[x][y][f],cnt);
                vis1[x][y]=1;
                q.pop();
                if(x+dx[f]>=0&&y+dy[f]>=0&&x+dx[f]<n&&y+dy[f]<m&&a[x+dx[f]][y+dy[f]]=='B'&&vis[x+dx[f]][y+dy[f]][f]>cnt){
                    q.push({x+dx[f],y+dy[f],cnt,f});
                    vis[x+dx[f]][y+dy[f]][f]=cnt;
                    vis1[x+dx[f]][y+dy[f]]=1;
                }
                    if(cnt==0){
                        for(int f1=0;f1<4;f1++){
                            if(f1==f){
                                continue;
                            }
                            if(x+dx[f1]>=0&&y+dy[f1]>=0&&x+dx[f1]<n&&y+dy[f1]<m&&a[x+dx[f1]][y+dy[f1]]=='B'&&vis[x+dx[f1]][y+dy[f1]][f1]>cnt){
                                q.push({x+dx[f1],y+dy[f1],cnt+1,f1});
                                vis[x+dx[f1]][y+dy[f1]][f1]=cnt+1;
                                vis1[x+dx[f1]][y+dy[f1]]=1;
                            }
                        }
                    }
            }
            for(int i1=0;i1<n;i1++){
                for(int j1=0;j1<m;j1++){
                    if(a[i1][j1]=='B'&&vis1[i1][j1]==-1){
                        // std::cerr<<i<<" "<<j<<" "<<i1<<" "<<j1<<endl;
                        std::cout<<"NO"<<endl;
                        return ;
                    }
                }
            }
        }
    }
    std::cout<<"YES"<<endl;
}
signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
