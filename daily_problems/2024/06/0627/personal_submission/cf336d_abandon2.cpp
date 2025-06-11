#include<bits/stdc++.h>
using namespace std;
const int N =1e3+10;

struct node{
    int l,r,u,v;
}e[N*3];
int x[N*3];

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n+1);
    }
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].l>>e[i].r;
        x[i]=e[i].l;
    }    
    sort(x+1,x+1+m);
    int ans=0,sz=0;
    auto check=[&](int l,int r)->int{
        DSU s(n);
        for(int i=1;i<=m;i++){
            if(e[i].l<=l&&e[i].r>=r){
                s.merge(e[i].u,e[i].v);
            }
        }
        if(s.same(1,n)){
            if(r-l+1>ans||(r-l+1==ans&&s.size(1)<sz)){
                sz=s.size(1);
                ans=r-l+1;
            }
            return 1;
        }
        return 0;
    };

    for(int i=1;i<=m;i++){
        int l=x[i]-1,r=1e6+1;
        while(l+1<r){
            int mid=l+r>>1;
            if(check(x[i],mid)) l=mid;
            else r=mid;
            //cout<<l<<" "<<r<<"\n";
        }
    }
    if(!ans){
        cout<<"Nice work, Dima!\n";return;
    }
    cout<<ans<<"\n";


}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
