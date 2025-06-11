/*
    Bonelight =^x^=
    20241117: 单枪匹马，无畏粉身碎骨
    我尝试过无数次了，但我知道，机会只会出现在其中的一两次
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define pii pair<int,int>
#define tiii tuple<int,int,int>  
#define INF 2e18
#define VC vector<int>
#define VCii vector<pii>
#define MAT vector<VC>
#define MATii vector<VCii>
#define For(_tag,x,y) for(int _tag = x; _tag <= y; _tag ++)
#define Rof(_tag,y,x) for(int _tag = y; _tag >= x; _tag --)
#define all(_tag) begin(_tag),end(_tag)
#define x first
#define y second

class UnionFind{
  public:
    VC X,out;
    int n;
    
    UnionFind(int n): n(n),X(n+1),out(n+1,-1){
        iota(all(X),0);
    }

    int find(int o){return X[o] = X[o] == o? o:find(X[o]);}

    void merge(int xx, int yy){
        int x = find(xx), y = find(yy);
        if(x == y) out[x] = xx;
        else X[x] = y;
    }
};

/*希望残酷的世界还能为我这样的蝼蚁留下一丝美好*/
void solve(){
    int n; cin >> n;
    VC a(n+1); 
    int root = 0;
    For(i,1,n){
        cin >> a[i];
        if(!root && a[i] == i) root = i; 
    } 

    UnionFind dsu(n+1);
    For(i,1,n){
        dsu.merge(i,a[i]);
    }

    VC change;
    VC vis(n+1);
    For(i,1,n){
        int rt = dsu.find(i) ; 
        if(rt == root) vis[rt] = 1;
        else if(!vis[rt]){
            vis[rt] = 1;
            change.emplace_back(dsu.out[rt]);
        }
    }
    
    if(root != 0){
        for(auto i:change) a[i] = root;
    } else {
        for(auto i:change) a[i] = change[0];
    }

    // for(auto i:change) cout << i << ' ';
    // cout << endl;
    cout << change.size() << endl;

    For(i,1,n) cout << a[i] << ' ';

}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    
    while(T --){
        solve();
    } 
}
