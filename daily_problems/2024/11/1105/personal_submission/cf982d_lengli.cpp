/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

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

constexpr int N=100010;

std::array<int,2> a[N];
bool st[N];

void solve(){
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++){
        std::cin>>a[i][0];
        a[i][1]=i;        
    }
    sort(a+1,a+1+n);

    DSU dsu(n+2);
    std::map<int,int> q;

    auto add=[&](int x){
        st[x]=1;
        if(st[x-1]){
            int l=dsu.size(x-1);
            q[l]--;
            if(q[l]==0) q.erase(l);
            dsu.merge(x-1,x);
        }
        if(st[x+1]){
            int l=dsu.size(x+1);
            q[l]--;
            if(q[l]==0) q.erase(l);
            dsu.merge(x+1,x);
        }
        q[dsu.size(x)]++;
    };
    int cnt=0,res=0;
    for(int i=1;i<=n;i++){
        int j=i;
        while(a[j][0]==a[i][0]){
            add(a[j][1]);
            j++;
        }
        if(q.size()==1){
            for(auto [c,v]:q){
                if(v>cnt) cnt=v,res=a[i][0]+1;
            }
        }
        i=j-1;
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
