/*
 * @Author: BlaCat
 */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
struct DSU {
    std::vector<int> f, siz;
    std::vector<int> val;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        val.assign(n,0);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
            val[x]+=val[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y,int d) {
        int x1 = find(x);
        int y1 = find(y);
        if (x1 == y1) {
            return val[x]-val[y]==d;
        }
        siz[x1] += siz[y1];
        f[y1] = x1;
        val[y1]=val[x]-d-val[y];
        find(x);
        find(y);
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
void solve(){
    int n,m;
    cin>>n>>m;
    DSU ds(n+5);
    int u,v,d;
    bool flag=0;
    for(int i=0;i<m;i++){
        cin>>u>>v>>d;
        if(!ds.merge(u,v,d)){
            flag=1;
        }
    }
    if(flag){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
