/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<char>> g(n,std::vector<char> (m));

    int cnt=0;
    for(auto &x:g) for(auto &y:x){
        std::cin>>y;
        if(y=='B') cnt++;
    }

    std::vector<int> dx={1,0,-1,0},dy={0,-1,0,1};

    auto bfs=[&](int x,int y){
        std::vector<std::vector<int>> st(n,std::vector<int> (m,0));
        std::queue<std::array<int,4>> q;
        int ans=1;
        st[x][y]=1;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0 or nx>=n or ny<0 or ny>=m) continue;
            if(g[nx][ny]=='B'){
                q.push({nx,ny,i,0});
            }
        }
        while(q.size()){
            auto [xx,yy,fx,k]=q.front();
            q.pop();
            if(!st[xx][yy]){
                st[xx][yy]=1;
                ans++;
            }
            for(int i=0;i<4;i++){
                int nx=xx+dx[i],ny=yy+dy[i];
                if(nx<0 or nx>=n or ny<0 or ny>=m) continue;
                if(g[nx][ny]=='B' and k+(i!=fx)<2){
                    q.push({nx,ny,i,k+(i!=fx)});
                }
            }
        }
        return ans==cnt;
    };

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='B' and !bfs(i,j)){
                std::cout<<"NO"<<"\n";
                return;
            }
        }
    }
    std::cout<<"YES"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
