/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=100002;

struct Info{//information
    i64 sum[5][12];

    Info() {};
    friend Info operator + (const Info &a,const Info &b){
        Info res;
        for(int i=2;i<=6;i++){
            for(int j=0;j<12;j++){
                res.sum[i-2][j]=a.sum[i-2][j]+b.sum[i-2][j];
            }
        }
        return res;
    };
};

int n;
int S[7][N];
i64 a[N];

struct Segment_tree{
    Info info[N*4];
    
    void pushup(int u){
        info[u]=info[u<<1]+info[u<<1|1];
    }
    
    void build(int u,int l,int r){
        if(l==r) {
            for(int z=2;z<=6;z++){
                int xhj=2*(z-1);
                for(int j=0;j<12;j++){
                    info[u].sum[z-2][j]=a[l]*S[z][((j+l)%xhj-1+xhj)%xhj+1];
                }
            }

        }else{
            int mid=(l+r)>>1;
            build(u<<1,l,mid);
            build(u<<1|1,mid+1,r);
            pushup(u);
        }
    }
    
    void modify(int u,int l,int r,int pl,int pr,i64 c){
        if(l>=pl and r<=pr) {
            for(int z=2;z<=6;z++){
                int xhj=2*(z-1);
                for(int j=0;j<12;j++){
                    info[u].sum[z-2][j]=c*S[z][((j+l)%xhj-1+xhj)%xhj+1];
                }
            }
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
    std::cin>>n;
    for(int i=1;i<=n;i++) std::cin>>a[i];

    for(int z=2;z<=6;z++){
        for(int i=1;i<=z*2;i++){
            int d=2*(z-1);
            if(i%d==0) S[z][i]=2;
            else if(i%d<=z) S[z][i]=i%d;
            else S[z][i]=2*z-i%d;
        }
    }

    tr.build(1,1,n);
    
    int m;
    std::cin>>m;
    while(m--){
        int op;
        std::cin>>op;
        if(op==1){
            int p,v;
            std::cin>>p>>v;
            tr.modify(1,1,n,p,p,v);
        }else{
            int l,r,z;
            std::cin>>l>>r>>z;
            auto t=tr.query(1,1,n,l,r);

            int xhj=2*(z-1);
            int len=(xhj-l%xhj);

            std::cout<<t.sum[z-2][len+1]<<"\n";
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
