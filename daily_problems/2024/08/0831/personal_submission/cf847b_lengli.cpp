/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int inf=1e9,N=200010;

struct Info{//information
    int l,r;
    int mi=inf;
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
            info[u].mi=inf;
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
    int n;
    std::cin>>n;
    std::vector<int> a(n+2),q;
    for(int i=1;i<=n;i++) std::cin>>a[i],q.pb(a[i]);
    sort(all(q));
    q.erase(unique(all(q)),q.end());

    std::vector<std::vector<int>> res;
    auto find=[&](int x){
        return lower_bound(all(q),x)-q.begin()+1;
    };
    tr.build(1,1,n);
    for(int i=1;i<=n;i++){
        int x=find(a[i]);
        if(x==1){
            std::vector<int> ans;
            ans.pb(a[i]);
            tr.modify(1,1,n,x,x,res.size());
            res.pb(ans);
        }else{
            auto t=tr.query(1,1,n,1,x-1).mi;
            if(t==inf){
                std::vector<int> ans;
                ans.pb(a[i]);
                tr.modify(1,1,n,x,x,res.size());
                res.pb(ans);
            }else{
                auto &p=res[t];
                tr.modify(1,1,n,find(p.back()),find(p.back()),inf);
                tr.modify(1,1,n,x,x,t);
                p.pb(a[i]);
            }
        }
    }
    for(auto x:res){
        for(auto c:x) std::cout<<c<<" ";
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
