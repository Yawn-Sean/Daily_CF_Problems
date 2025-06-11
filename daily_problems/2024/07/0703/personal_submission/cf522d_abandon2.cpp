#include<bits/stdc++.h>
using namespace std;
#define lp p<<1
#define rp p<<1|1
const int N=5e5+10,inf=1e9;
int w[N],pre[N],pos[N];
int n,m;
vector<array<int,2>>g[N];
struct tree{
    int l,r,mn;
}tr[N*4];

void pushup(int p){
    tr[p].mn=min(tr[lp].mn,tr[rp].mn);
}

void build(int p,int l,int r){
    tr[p].l=l,tr[p].r=r,tr[p].mn=inf;
    if(l==r){
        return;
    }
    int mid=l+r>>1;
    if(l<=mid)build(lp,l,mid);
    if(r>mid)build(rp,mid+1,r);
    pushup(p);
}

void updata(int p,int k,int x){
    if(tr[p].l==tr[p].r&&tr[p].l==k){
        tr[p].mn=x;return;
    }
    int mid=tr[p].l+tr[p].r>>1;
    if(k<=mid)updata(lp,k,x);
    else updata(rp,k,x);
    pushup(p);
}

int ask(int p,int l,int r){
    if(l<=tr[p].l&&tr[p].r<=r){
        return tr[p].mn;
    }
    int mid=tr[p].l+tr[p].r>>1;
    int mn=inf;
    if(l<=mid)mn=min(mn,ask(lp,l,r));
    if(r>mid)mn=min(mn,ask(rp,l,r));
    return mn;
}

void solve(){
    cin>>n>>m;
    std::vector<int> v(n+1),a(n+1),ans(m+1,inf);
    for(int i=1;i<=n;i++){
        cin>>v[i];a[i]=v[i];
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;i++)
         a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin();
    
    for(int i=1;i<=n;i++){
        pre[i]=pos[a[i]];
        pos[a[i]]=i;
    }
    build(1,1,n);
    
    for(int i=1;i<=m;i++){
         int l,r;cin>>l>>r;
         g[r].push_back({l,i});
    }
    
    for(int i=1;i<=n;i++){
        if(pre[i])updata(1,pre[i],i-pre[i]);
        for(auto [x,id]:g[i]){
            ans[id]=ask(1,x,i);
        }
    }
    for(int i=1;i<=m;i++){
        cout<<(ans[i]==inf?-1:ans[i])<<"\n";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
