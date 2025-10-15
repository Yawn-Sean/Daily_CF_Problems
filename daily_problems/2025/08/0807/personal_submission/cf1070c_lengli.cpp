/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=1000010;

struct Info{//information
    i64 cnt=0,sum=0;

    Info() {};
    friend Info operator + (const Info &a,const Info &b){
        Info res;
        res.cnt=a.cnt+b.cnt;
        res.sum=a.sum+b.sum;
        
        return res;
    };
};

struct Segment_tree{
    Info info[N*4];
    char a[N];
    
    void pushup(int u){
        info[u]=info[u<<1]+info[u<<1|1];
    }
    
    void build(int u,int l,int r){
        if(l==r) {
            info[u].cnt=0,info[u].sum=0;
        }else{
            int mid=(l+r)>>1;
            build(u<<1,l,mid);
            build(u<<1|1,mid+1,r);
            pushup(u);
        }
    }
    
    void modify(int u,int l,int r,int pl,int pr,i64 c){
        if(l>=pl and r<=pr) {
            info[u].cnt+=c;
            info[u].sum+=1ll*c*l;
            return;
        }
        int mid=(l+r)>>1;
        if(pl<=mid) modify(u<<1,l,mid,pl,pr,c);
        if(pr>mid) modify(u<<1|1,mid+1,r,pl,pr,c);
        pushup(u);
    }

    i64 query(int u,int l,int r,int k){
        if(l==r) return 1ll*k*l;
        int mid=(l+r)>>1;
        if(k<=info[u<<1].cnt) return query(u<<1,l,mid,k);
        else return info[u<<1].sum+query(u<<1|1,mid+1,r,k-info[u<<1].cnt);
    }

}tr;

void solve(){
    int n,k,m;
    std::cin>>n>>k>>m;
    std::vector<std::array<int,3>> qr(m*2);
    for(int i=0;i<m;i++){
        int l,r,c,p;
        std::cin>>l>>r>>c>>p;
        qr[i]={l,c,p};
        qr[m+i]={r+1,-c,p};
    }
    tr.build(1,1,N-1);
    std::sort(all(qr));

    i64 res=0;
    for(int i=1,j=0;i<=n;i++){
        while(j<m*2 and qr[j][0]<=i){
            tr.modify(1,1,N-1,qr[j][2],qr[j][2],qr[j][1]);
            j++;
        }
        if(tr.info[1].cnt<k) res+=tr.info[1].sum;
        else{
            res+=tr.query(1,1,N-1,k);
        }
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
