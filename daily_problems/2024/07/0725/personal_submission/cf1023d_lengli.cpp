/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

struct Tag{//lazy tag
    long long add=0,mul=1;
    Tag(int a=0,int b=1):add(a),mul(b) {};
    void apply(Tag t){
        add=(add*t.mul+t.add);
        mul=(mul*t.mul);
    };
};

struct Info{//information
    int l,r;
    long long sum;
    Info() {};
    void apply(Tag t){
        sum=sum*t.mul+(r-l+1)*t.add;
    };
    friend Info operator + (const Info &a,const Info &b){
        Info res;
        res.l=a.l,res.r=b.r;
        res.sum=a.sum+b.sum;
        return res;
    };
};

const int N=200010;

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
        info[u].l=l,info[u].r=r;
        if(l==r) {
            info[u].l=l,info[u].r=r;
            info[u].sum=1;
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

int a[N];
int ll[N],rr[N];

void solve(){
    int n,q;
    std::cin>>n>>q;
    std::vector<int> a(n+2);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        if(ll[a[i]]) rr[a[i]]=i;
        else ll[a[i]]=rr[a[i]]=i;
    }

    if(!ll[q] and !ll[0]){
        std::cout<<"NO"<<"\n";
        return;
    }else if(!ll[q]) ll[q]=ll[0],rr[q]=ll[0];
    tr.build(1,1,n);
    for(int i=1;i<=q;i++){
        if(!ll[i]) tr.modify(1,1,n,ll[q],rr[q],Tag(i,0));
        else tr.modify(1,1,n,ll[i],rr[i],Tag(i,0));
    }
    for(int i=1;i<=n;i++){
        int v=tr.query(1,1,n,i,i).sum;
        if(!a[i]) a[i]=v;
        else{
            if(a[i]!=v){
                std::cout<<"NO"<<"\n";
                return;
            }
        }
    }
    std::cout<<"YES"<<"\n";
    for(int i=1;i<=n;i++) std::cout<<a[i]<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
