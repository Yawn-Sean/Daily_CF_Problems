#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 =long long;
using d64= double;
using ld64= long double;
#define endl '\n'

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::string> a(n);
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
    int sx,sy,tx,ty;
    std::cin>>sx>>sy>>tx>>ty;
    sx--;
    sy--;
    tx--;
    ty--;
    bool vis[n+1][m+1][4];
    memset(vis,0,sizeof(vis));
    std::map<char,std::vector<char>> mp;
    mp['^']={'^','>','v','<'};
    mp['>']={'>','v','<','^'};
    mp['<']={'<','^','>','v'};
    mp['v']={'v','<','^','>'};
    mp['+']={'+','+','+','+'};
    mp['-']={'-','|','-','|'};
    mp['|']={'|','-','|','-'};
    mp['*']={'*','*','*','*'};
    mp['U']={'U','R','D','L'};
    mp['R']={'R','D','L','U'};
    mp['D']={'D','L','U','R'};
    mp['L']={'L','U','R','D'};
    std::map<int,std::vector<int>> mp1;
    //上下左右
    mp1['^']={1,0,0,0};
    mp1['>']={0,0,0,1};
    mp1['<']={0,0,1,0};
    mp1['v']={0,1,0,0};
    mp1['+']={1,1,1,1};
    mp1['-']={0,0,1,1};
    mp1['|']={1,1,0,0};
    mp1['*']={0,0,0,0};
    mp1['U']={0,1,1,1};
    mp1['R']={1,1,1,0};
    mp1['D']={1,0,1,1};
    mp1['L']={1,1,0,1};
    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};
    int duiy[]={1,0,3,2};
    std::queue<std::array<int,4>> q;
    q.push({sx,sy,0,0});
    while(!q.empty()){
        auto [x,y,z,l]=q.front();
        q.pop();
        if(vis[x][y][z]){
            continue;
        }
        if(x==tx&&y==ty){
            std::cout<<l<<endl;
            return ;
        }
        vis[x][y][z]=1;
        q.push({x,y,(z+1)%4,l+1});
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m){
                continue;
            }
            
            if(mp1[mp[a[x][y]][z]][i]==1&&mp1[mp[a[nx][ny]][z]][duiy[i]]){
                q.push({nx,ny,z,l+1});
            }
        }
    }
    std::cout<<-1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--){
        solve();
    }
}
