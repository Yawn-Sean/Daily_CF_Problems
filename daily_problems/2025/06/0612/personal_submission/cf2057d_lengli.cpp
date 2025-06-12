/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=200010;
constexpr int inf=1e9;

struct Info{//information
    int mx_add=0,mi_add=inf;
    int mx_dif=0,mi_dif=inf;
    int sum=0;

    Info() {};
    friend Info operator + (const Info &a,const Info &b){
        Info res;
        res.mx_add=std::max(a.mx_add,b.mx_add);
        res.mi_add=std::min(a.mi_add,b.mi_add);

        res.mx_dif=std::max(a.mx_dif,b.mx_dif);
        res.mi_dif=std::min(a.mi_dif,b.mi_dif);

        res.sum=std::max(a.sum,b.sum);
        res.sum=std::max(res.sum,a.mx_add-b.mi_add);
        res.sum=std::max(res.sum,b.mx_dif-a.mi_dif);
        
        return res;
    };
};

int n,q;
int a[N];

struct Segment_tree{
    Info info[N*4];

    void pushup(int u){
        info[u]=info[u<<1]+info[u<<1|1];
    }
    
    void build(int u,int l,int r){
        if(l==r) {
            info[u].mx_add=a[l]+l;
            info[u].mi_add=a[l]+l;
            info[u].mx_dif=a[l]-l;
            info[u].mi_dif=a[l]-l;
            info[u].sum=0;
        }else{
            int mid=(l+r)>>1;
            build(u<<1,l,mid);
            build(u<<1|1,mid+1,r);
            pushup(u);
        }
    }
    
    void modify(int u,int l,int r,int pl,int pr,int c){
        if(l>=pl and r<=pr) {
            a[l]=c;
            info[u].mx_add=a[l]+l;
            info[u].mi_add=a[l]+l;
            info[u].mx_dif=a[l]-l;
            info[u].mi_dif=a[l]-l;
            info[u].sum=0;
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
    std::cin>>n>>q;
    for(int i=1;i<=n;i++) std::cin>>a[i];
    tr.build(1,1,n);
    std::cout<<tr.query(1,1,n,1,n).sum<<"\n";
    while(q--){
        int x,c;
        std::cin>>x>>c;
        tr.modify(1,1,n,x,x,c);
        std::cout<<tr.query(1,1,n,1,n).sum<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
