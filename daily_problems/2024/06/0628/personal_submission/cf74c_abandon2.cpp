#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;

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
    DSU s(n*2+m*2);

    auto get=[&](int x,int y)->int{
        if(x==1)return y;//上边界
        if(y==m) return m+x-1;
        if(x==n) return m*2+n-y-1;
        if(y==1) return n*2+m*2-x-2; 
        return 0;
    };
    if(n<m)swap(n,m);
    for(int i=1;i<=n;i++){
        if(i<=m){
            s.merge(get(i,1),get(1,i));
            s.merge(get(i,m),get(1,m-i+1));
        }
        else{
            s.merge(get(i,1),get(i-m+1,m));
            s.merge(get(i,m),get(i-m+1,1));
        }
        if(i>=n-m+1){
            s.merge(get(i,1),get(n,n-i+1));
            s.merge(get(i,m),get(n,m-n+i));
        }
        else{
            s.merge(get(i,1),get(i+m-1,m));
            s.merge(get(i,m),get(i+m-1,1));
        }
    }
    int cnt =0;
    for(int i=1;i<=(n+m)*2-4;i++){
        if(s.find(i)==i){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
