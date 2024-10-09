/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int N=1000010;

constexpr long long inf=1e10;

#define int long long

struct Tag{//lazy tag
    int add=0;
    Tag(int a=0):add(a){};
    void apply(Tag t){
        add+=t.add;
    };
};

struct Info{//information
    int sum=0;
    int mx=-inf;
    Info() {};
    void apply(Tag t){
        sum+=t.add;
        mx+=t.add;
    };
    friend Info operator + (const Info &a,const Info &b){
        Info res;
        res.sum=a.sum+b.sum;
        res.mx=std::max(a.mx,b.mx);
        return res;
    };
};

int a[N],b[N];

struct Segment_tree{
    Info info[N*4];
    Tag tag[N*4];
    
    void pushup(int u){
        info[u]=info[u<<1]+info[u<<1|1];
    }
    
    void apply(int u,const Tag &t){
        info[u].apply(t);
        tag[u].apply(t);
    }
    
    void pushdown(int u){
        apply(u<<1,tag[u]);
        apply(u<<1|1,tag[u]);
        tag[u]=Tag();
    }
    
    void build(int u,int l,int r){
        tag[u]=Tag();
        if(l==r) {
            info[u].sum=-a[l];
            info[u].mx=-a[l];
        }else{
            int mid=(l+r)>>1;
            build(u<<1,l,mid);
            build(u<<1|1,mid+1,r);
            pushup(u);
        }
    }
    
    void modify(int u,int l,int r,int pl,int pr,const Tag &t){
        if(l>=pl and r<=pr) {
            apply(u,t);
            return;
        }
        pushdown(u);
        int mid=(l+r)>>1;
        if(pl<=mid) modify(u<<1,l,mid,pl,pr,t);
        if(pr>mid) modify(u<<1|1,mid+1,r,pl,pr,t);
        pushup(u);
    }
    
    Info query(int u,int l,int r,int pl,int pr){
        if(l>=pl and r<=pr) return info[u];
        pushdown(u);
        int mid=(l+r)>>1;
        if(pl>mid) return query(u<<1|1,mid+1,r,pl,pr);
        else if(pr<=mid) return query(u<<1,l,mid,pl,pr);
        else return query(u<<1,l,mid,pl,pr)+query(u<<1|1,mid+1,r,pl,pr);
    }
}tr;

void solve(){
    int n,m,p;
    std::cin>>n>>m>>p;
    for(int i=0;i<N;i++) a[i]=b[i]=inf;
    for(int i=1;i<=n;i++){
        int x,v;
        std::cin>>x>>v;
        b[x-1]=std::min(b[x-1],v);
    }
    for(int i=1;i<=m;i++){
        int x,v;
        std::cin>>x>>v;
        a[x-1]=std::min(a[x-1],v);
    }
    for(int i=N-2;i>=0;i--){
        a[i]=std::min(a[i],a[i+1]);
        b[i]=std::min(b[i],b[i+1]);
    }
    tr.build(1,1,N-10);
    std::vector<std::array<int,3>> pt(p);
    for(auto &[hp,ad,v]:pt) std::cin>>hp>>ad>>v;

    long long res=-inf;
    sort(all(pt));
    for(int i=1,j=0;i<=N-10;i++){
        while(j<p and pt[j][0]<=i){
            tr.modify(1,1,N-10,pt[j][1],N-10,Tag(pt[j][2]));
            j++;
        }
        long long ans=tr.query(1,1,N-10,1,N-10).mx-b[i];
        res=std::max(res,ans);
    }
    if(res==-inf) res=-(a[0]+b[0]);
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
