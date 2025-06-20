/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

template <unsigned M_> struct ModInt {
  static constexpr unsigned M = M_;
  unsigned x;
  constexpr ModInt() : x(0U) {}
  constexpr ModInt(unsigned x_) : x(x_ % M) {}
  constexpr ModInt(unsigned long long x_) : x(x_ % M) {}
  constexpr ModInt(int x_) : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_) {}
  constexpr ModInt(long long x_) : x(((x_ %= static_cast<long long>(M)) < 0) ? (x_ + static_cast<long long>(M)) : x_) {}
  ModInt &operator+=(const ModInt &a) { x = ((x += a.x) >= M) ? (x - M) : x; return *this; }
  ModInt &operator-=(const ModInt &a) { x = ((x -= a.x) >= M) ? (x + M) : x; return *this; }
  ModInt &operator*=(const ModInt &a) { x = (static_cast<unsigned long long>(x) * a.x) % M; return *this; }
  ModInt &operator/=(const ModInt &a) { return (*this *= a.inv()); }
  ModInt pow(long long e) const {
    if (e < 0) return inv().pow(-e);
    ModInt a = *this, b = 1U; for (; e; e >>= 1) { if (e & 1) b *= a; a *= a; } return b;
  }
  ModInt inv() const {
    unsigned a = M, b = x; int y = 0, z = 1;
    for (; b; ) { const unsigned q = a / b; const unsigned c = a - q * b; a = b; b = c; const int w = y - static_cast<int>(q) * z; y = z; z = w; }
    assert(a == 1U); return ModInt(y);
  }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { ModInt a; a.x = x ? (M - x) : 0U; return a; }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
  template <class T> friend ModInt operator+(T a, const ModInt &b) { return (ModInt(a) += b); }
  template <class T> friend ModInt operator-(T a, const ModInt &b) { return (ModInt(a) -= b); }
  template <class T> friend ModInt operator*(T a, const ModInt &b) { return (ModInt(a) *= b); }
  template <class T> friend ModInt operator/(T a, const ModInt &b) { return (ModInt(a) /= b); }
  explicit operator bool() const { return x; }
  bool operator==(const ModInt &a) const { return (x == a.x); }
  bool operator!=(const ModInt &a) const { return (x != a.x); }
  bool operator<(const ModInt &a) const { return (x < a.x); }
  bool operator>(const ModInt &a) const { return (x > a.x); }
  bool operator<=(const ModInt &a) const { return (x <= a.x); }
  bool operator>=(const ModInt &a) const { return (x >= a.x); }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x; }
  friend std::istream &operator>>(std::istream &is, ModInt &a) {int v;is >> v;a = ModInt(v);return is;}
};
constexpr unsigned MO = 1000000007;
using Mint = ModInt<MO>;

struct HLD{
    int n,cnt;
    std::vector<int> sz,dep,top,son,fa,in,out,seq;
    std::vector<std::vector<std::array<int,2>>> g;

    std::vector<std::vector<int>> dif;

    void init(int nn,std::vector<std::vector<std::array<int,2>>> &eg,int root){
        n=nn;cnt=0;g=eg;
        sz.clear(),dep.clear();
        top.clear(),seq.clear();
        son.clear(),fa.clear();
        in.clear(),out.clear();
        sz.resize(n+1),dep.resize(n+1);
        top.resize(n+1),seq.resize(n+1);
        son.resize(n+1),fa.resize(n+1);
        in.resize(n+1),out.resize(n+1);
        dif.resize(n+1,std::vector<int> (2,0));
        
        dep[root] = 1;
        top[root] = root;
        dfs1(root);
        dfs2(root);
    };
    void dfs1(int u){
        if(fa[u]){
            for(int i=0;i<g[u].size();i++){
                if(g[u][i][0]==fa[u]){
                    g[u].erase(g[u].begin()+i,g[u].begin()+i+1);
                    break;
                }
            }
        }
        sz[u]=1;
        for(auto &t:g[u]){
            auto [j,st]=t;
            fa[j]=u;
            dep[j]=dep[u]+1;
            dfs1(j);
            sz[u]+=sz[j];
            if (sz[j]>sz[g[u][0][0]])
                std::swap(t,g[u][0]);
        }
    }
    void dfs2(int u){
        in[u]=++cnt;
        seq[in[u]]=u;
        //do something
        for (auto [j,st] : g[u]){
            top[j]=(j == g[u][0][0] ? top[u] : j);
            dfs2(j);
        }
        out[u]=cnt;
    }
    int lca(int u,int v){
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]]) v=fa[top[v]];
            else u=fa[top[u]];
        }
        return dep[u]<dep[v] ? u : v;
    }
    int dist(int u,int v){
        return dep[u]+dep[v]-2*dep[lca(u,v)];
    }
    
    void add(int u,int v){
        int t=lca(u,v);
        dif[u][0]++,dif[t][0]--;
        dif[v][1]++,dif[t][1]--;
    }

}hld;

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::vector<std::array<int,2>>> eg(n+2);
    for(int i=1;i<n;i++){
        int u,v,t;
        std::cin>>u>>v>>t;
        if(t==0){
            eg[u].pb({v,0});
            eg[v].pb({u,0});
        }else{
            eg[u].pb({v,0});
            eg[v].pb({u,1});
        }
    }
    hld.init(n,eg,1);
    int start=1;
    int m;
    std::cin>>m;
    for(int i=1;i<=m;i++){
        int x;
        std::cin>>x;
        hld.add(start,x);
        start=x;
    }
    Mint res=0;

    auto dfs=[&](auto self,int u,int fa)->void{
        for(auto [x,st]:eg[u]){
            if(x==fa) continue;
            self(self,x,u);
            hld.dif[u][0]+=hld.dif[x][0];
            hld.dif[u][1]+=hld.dif[x][1];
        }
    };


    auto getans=[&](auto self,int u,int fa)->void{
        for(auto [x,st]:eg[u]){
            if(st){
                int cnt=0;
                if(hld.dep[u]>hld.dep[x]) cnt=hld.dif[u][0];
                else cnt=hld.dif[x][1];
                res+=Mint(2).pow(cnt)-1;
            }
        }
        for(auto [x,st]:eg[u]){
            if(x==fa) continue;
            self(self,x,u);
        }
    };

    dfs(dfs,1,0);
    getans(getans,1,0);
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
