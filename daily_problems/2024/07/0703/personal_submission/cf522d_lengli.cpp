/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

const int N=500010;

struct Info{//information
    int l,r;
    int mi;
    Info() {};
    friend Info operator + (const Info &a,const Info &b){
        Info res;
        res.l=a.l,res.r=b.r;
        res.mi=std::min(a.mi,b.mi);
        return res;
    };
};

struct Segment_tree{
    Info info[N*4];
    
    void pushup(int u){
        info[u]=info[u<<1]+info[u<<1|1];
    }
    
    void build(int u,int l,int r){
        info[u].l=l,info[u].r=r;
        if(l==r) {
            info[u].mi=1e9;
        }else{
            int mid=(l+r)>>1;
            build(u<<1,l,mid);
            build(u<<1|1,mid+1,r);
            pushup(u);
        }
    }
    
    void modify(int u,int l,int r,int pl,int pr,int c){
        if(l>=pl and r<=pr) {
            info[u].mi=c;
            return;
        }
        int mid=(l+r)>>1;
        if(pl<=mid) modify(u<<1,l,mid,pl,pr,c);
        if(pr>mid) modify(u<<1|1,mid+1,r,pl,pr,c);
        pushup(u);
    }
    
    Info query(int u,int l,int r,int pl,int pr){
        if(l>=pl and r<=pr) return info[u];
        int mid=(l+r)>>1;
        if(pl>mid) return query(u<<1|1,mid+1,r,pl,pr);
        else if(pr<=mid) return query(u<<1,l,mid,pl,pr);
        else return query(u<<1,l,mid,pl,pr)+query(u<<1|1,mid+1,r,pl,pr);
    }
}tr;

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::map<int,int> la;
    std::vector<std::array<int,2>> a;
    for(int i=1;i<=n;i++){
        int x;
        std::cin>>x;
        if(la.count(x)) a.pb({la[x],i});
        la[x]=i;
    }
    std::vector<std::array<int,3>> qr;
    for(int i=1;i<=m;i++){
        int l,r;
        std::cin>>l>>r;
        qr.pb({l,r,i});
    }
    sort(all(a)),sort(all(qr));
    tr.build(1,1,N);
    for(auto [l,r]:a){
        tr.modify(1,1,n,r,r,r-l);
    }
    std::vector<int> res(m+2);
    for(int i=0,j=0;i<m;i++){
        auto [l,r,id]=qr[i];
        while(j<a.size() and a[j][0]<l){
            tr.modify(1,1,n,a[j][1],a[j][1],1e9);
            j++;
        }
        auto t=tr.query(1,1,n,l,r).mi;
        res[id]=(t==1e9 ? -1 : t);
    }
    for(int i=1;i<=m;i++) std::cout<<res[i]<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
