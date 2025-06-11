/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

struct DSU{
    std::vector<int> p, sz,add;
    DSU(int n): p(n), sz(n, 1),add(n,0){
        std::iota(p.begin(), p.end(), 0);
    }
    int find(int x){
        return x == p[x] ? x : p[x]=find(p[x]);
    }
    int sum(int x){
        return x == p[x] ? add[x] : add[x]+sum(p[x]);
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
    bool merge(int x, int y){
        x = find(x);
        y = find(y);
        if (x == y) return 0;
        if(size(x) < size(y)) std::swap(x,y);
        sz[x] += sz[y];
        p[y] = x;
        add[y]-=add[x];
        return 1;
    }
    int size(int x){
        return sz[find(x)];
    }
};

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<char>> g(n,std::vector<char> (m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            std::cin>>g[i][j];
        }
    }

    DSU dsu(n*m+2);

    auto get=[&](int x,int y){
        return x*m+y;
    };
    
    std::vector<int> dx={1,0,-1,0},dy={0,-1,0,1};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='*') continue;
            for(int k=0;k<4;k++){
                int nx=i+dx[k],ny=j+dy[k];
                if(nx<0 or nx>=n or ny<0 or ny>=m or g[nx][ny]=='*') continue;
                dsu.merge(get(i,j),get(nx,ny));
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='*'){
                std::set<int> s;
                int res=0;
                for(int k=0;k<4;k++){
                    int nx=i+dx[k],ny=j+dy[k];
                    if(nx<0 or nx>=n or ny<0 or ny>=m or g[nx][ny]=='*') continue;
                    int v=dsu.find(get(nx,ny));
                    if(s.count(v)) continue;
                    s.insert(v);
                    res+=dsu.size(get(nx,ny));
                }
                std::cout<<(res+1)%10;
            }else std::cout<<".";
        }
        std::cout<<"\n";
    } 
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
