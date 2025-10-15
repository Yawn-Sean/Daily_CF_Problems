/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

#define int long long


struct DSU{
    std::vector<int> p, sz;
    DSU(int n): p(n), sz(n, 1){
        std::iota(p.begin(), p.end(), 0);
    }
    int find(int x){
        return x == p[x] ? x : p[x]=find(p[x]);
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
        return 1;
    }
    int size(int x){
        return sz[find(x)];
    }
};

void solve(){
    int n,m,sum;
    std::cin>>n>>m>>sum;

    std::vector<std::array<int,3>> a;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            std::cin>>x;
            a.pb({x,i,j});
        }
    }
    auto get=[&](int i,int j){
        return (i-1)*m+j;
    };
    sort(all(a),std::greater<>());
    std::vector<int> dx={1,0,-1,0},dy={0,-1,0,1};

    DSU dsu(n*m+10);

    std::vector<int> st(n*m+10);

    int k=-1,val=-1;

    for(int i=1;i<=a.size();i++){
        auto [v,x,y]=a[i-1];
        auto id=get(x,y);
        for(int j=0;j<4;j++){
            int nx=x+dx[j],ny=y+dy[j];
            if(nx<1 or nx>n or ny<1 or ny>m) continue;
            auto t=get(nx,ny);
            if(!st[t]) continue;
            dsu.merge(t,id);
        }

        auto sz=dsu.size(id);
        if(sz*v>=sum and sum%v==0){
            k=i;val=sz;
            break;
        }
        st[id]=1;
    }
    std::vector<std::vector<int>> res(n+2,std::vector<int> (m+2,0)); 
    if(k!=-1){
        int cnt=sum/a[k-1][0];
        int sum_res=0;
        auto dfs=[&](auto self,int x,int y,int v){
            if(!cnt) return;
            cnt--;
            res[x][y]=v;
            sum_res+=v;
            for(int j=0;j<4;j++){
                int nx=x+dx[j],ny=y+dy[j];
                if(nx<1 or nx>n or ny<1 or ny>m) continue;
                auto t=get(nx,ny);
                if(!st[t] or res[nx][ny]) continue;
                self(self,nx,ny,v);
            }
        };

        dfs(dfs,a[k-1][1],a[k-1][2],a[k-1][0]);

        if(sum_res!=sum) k=-1;
    }

    if(k==-1) std::cout<<"NO"<<"\n";
    else{
        std::cout<<"YES"<<"\n";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                std::cout<<res[i][j]<<" ";
            }
            std::cout<<"\n";
        }
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
