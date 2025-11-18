/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

struct Info{//information
    int mx=0;
    Info() {};
    friend Info operator + (const Info &a,const Info &b){
        Info res;
        res.mx=std::min(a.mx,b.mx);
        return res;
    };
};

constexpr int N=500010;

struct Segment_tree{
    Info info[N*4];
    
    void pushup(int u){
        info[u]=info[u<<1]+info[u<<1|1];
    }
    
    void build(int u,int l,int r){
        if(l==r) {
            info[u].mx=0;
        }else{
            int mid=(l+r)>>1;
            build(u<<1,l,mid);
            build(u<<1|1,mid+1,r);
            pushup(u);
        }
    }
    
    void modify(int u,int l,int r,int pl,int pr,int c){
        if(l>=pl and r<=pr) {
            info[u].mx=std::max(info[u].mx,c);
            return;
        }
        int mid=(l+r)>>1;
        if(pl<=mid) modify(u<<1,l,mid,pl,pr,c);
        if(pr>mid) modify(u<<1|1,mid+1,r,pl,pr,c);
        pushup(u);
    }
    
    int query(int u,int l,int r,int x){
        if(l>r) return 0;
        if(l==r){
            if(info[u].mx>=x) return 0;
            return l;
        }
        int mid=(l+r)>>1;


        if(r<=x){
            if(info[u<<1|1].mx<x) return query(u<<1|1,mid+1,r,x);
            return query(u<<1,l,mid,x);
        }

        if(x>mid){
            return std::max(query(u<<1,l,mid,x),query(u<<1|1,mid+1,r,x));
        }else{
            return query(u<<1,l,mid,x);
        }
    }
}tr;

void solve(){
    int n,q;
    std::cin>>n>>q;
    tr.build(1,0,n);
    for(int i=1;i<=q;i++){
        int op;
        std::cin>>op;
        if(op==1){
            int l,r;
            std::cin>>l>>r;
            tr.modify(1,0,n,l,l,r);
        }else{
            int x;
            std::cin>>x;
            std::cout<<x-tr.query(1,0,n,x)+1<<"\n";
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
