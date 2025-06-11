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
    int v;
    Info() {};
    friend Info operator + (const Info &a,const Info &b){
        Info res;
        res.v=a.v+b.v;
        
        return res;
    };
};

constexpr int N=300010;

int a[N];

struct Segment_tree{
    Info info[N*4];
    
    void pushup(int u){
        info[u]=info[u<<1]+info[u<<1|1];
    }
    
    void build(int u,int l,int r){
        if(l==r) {
            info[u].v=a[l];
        }else{
            int mid=(l+r)>>1;
            build(u<<1,l,mid);
            build(u<<1|1,mid+1,r);
            pushup(u);
        }
    }
    
    void modify(int u,int l,int r,int pl,int pr,int c){
        if(l>=pl and r<=pr) {
            info[u].v=c;
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
    std::vector<int> w(n+2),id(n+2);
    for(int i=1;i<=n;i++) {
        std::cin>>w[i];
        id[w[i]]=i;
    }
    for(int i=1;i<n;i++){
        if(id[i]>id[i+1]) a[i+1]=1;
    }
    tr.build(1,1,n);
    int q;
    std::cin>>q;
    while(q--){
        int op,l,r;
        std::cin>>op>>l>>r;
        if(op==1){
            if(l==r) std::cout<<1<<"\n";
            else{
                auto t=tr.query(1,1,n,l+1,r);
                std::cout<<t.v+1<<"\n";
            }
        }else{
            std::swap(id[w[l]],id[w[r]]);
            std::swap(w[l],w[r]);
            if(w[l]>1){
                if(id[w[l]]<id[w[l]-1]) tr.modify(1,1,n,w[l],w[l],1);
                else tr.modify(1,1,n,w[l],w[l],0);
            }
            if(w[l]<n){
                if(id[w[l]+1]<id[w[l]]) tr.modify(1,1,n,w[l]+1,w[l]+1,1);
                else tr.modify(1,1,n,w[l]+1,w[l]+1,0);
            }
            if(w[r]>1){
                if(id[w[r]]<id[w[r]-1]) tr.modify(1,1,n,w[r],w[r],1);
                else tr.modify(1,1,n,w[r],w[r],0);
            }
            if(w[r]<n){
                if(id[w[r]+1]<id[w[r]]) tr.modify(1,1,n,w[r]+1,w[r]+1,1);
                else tr.modify(1,1,n,w[r]+1,w[r]+1,0);
            }
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
