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
    std::vector<std::vector<char>> s(n,std::vector<char>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin>>s[i][j];
        }
    }
    std::vector<std::vector<int>> a(n,std::vector<int>(m,0));

    std::map<char,int> p={
        {'+',15},{'-',10},{'|',5},{'^',1},
        {'>',8},{'<',2},{'v',4},{'L',13},
        {'R',7},{'U',14},{'D',11},{'*',0}
    };

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j]=p[s[i][j]];
        }
    }

    int sx,sy,ex,ey;
    std::cin>>sx>>sy>>ex>>ey;
    sx--;sy--;ex--;ey--;
    std::vector<std::vector<std::vector<int>>> st(n,std::vector<std::vector<int>>(m,std::vector<int>(4,-1)));
    std::queue<std::array<int,4>> q;
    q.push({sx,sy,0,0});

    std::vector<int> dx={-1,1,0,0},dy={0,0,-1,1};
    std::vector<std::vector<int>> dz={
        {0,2},{2,0},{1,3},{3,1}
    };

    auto rotate=[&](int x,int t){
        int res=(x>>t) | (x<<(4-t));
        res&=15;
        return res;
    };

    while(q.size()){
        auto [x,y,z,v]=q.front();
        q.pop();
        if(st[x][y][z]!=-1) continue;
        st[x][y][z]=v;
        int t=st[x][y][z];
        if(x==ex and y==ey){
            std::cout<<t<<'\n';
            return;
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<0 or nx>=n or ny<0 or ny>=m) continue;
            bool f1=rotate(a[x][y],z)>>dz[i][0]&1;
            bool f2=rotate(a[nx][ny],z)>>dz[i][1]&1;
            if(f1 and f2) q.push({nx,ny,z,t+1});
        }
        q.push({x,y,(z+1)%4,t+1});
    }

    std::cout<<"-1"<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
