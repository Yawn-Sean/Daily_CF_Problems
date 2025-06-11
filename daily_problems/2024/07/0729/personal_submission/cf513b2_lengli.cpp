/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

//u,r,d,l
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void solve(){
    int n,m,q;
    std::cin>>n>>m>>q;
    std::vector<int> s(q+2);
    for(int i=1;i<=q;i++) std::cin>>s[i];
    std::vector<std::vector<int>> g(n+2,std::vector<int> (m+2,0));
    std::vector<std::array<int,3>> start;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            std::cin>>c;
            if(c=='#') g[i][j]=-1;
            else if(c=='.') continue;
            else{
                g[i][j]=c-'0';
                start.pb({g[i][j],i,j});
            }
        }
    }
    std::queue<std::array<int,3>> que;
    std::queue<std::array<int,4>> qq;
    sort(all(start));
    for(auto x:start) que.push(x);
    std::vector<std::vector<int>> st(n+2,std::vector<int> (m+2,0));
    while(que.size()){
        auto t=que.front();
        que.pop();
        qq.push({t[0],t[1],t[2],0});
        int ti=s[t[0]];
        while(qq.size()){
            auto [id,xx,yy,k]=qq.front();
            qq.pop();
            if(k==ti){
                que.push({id,xx,yy});
                continue;
            }
            for(int i=0;i<4;i++){
                int nx=xx+dx[i],ny=yy+dy[i];
                if(nx<1 or nx>n or ny<1 or ny>m or g[nx][ny]==-1 or g[nx][ny]>0) continue;
                g[nx][ny]=id;
                qq.push({id,nx,ny,k+1});
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         std::cout<<g[i][j]<<" ";
    //     }
    //     std::cout<<"\n";
    // }

    std::vector<int> res(q+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(g[i][j]>=1) res[g[i][j]]++;
        }
    for(int i=1;i<=q;i++) std::cout<<res[i]<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
