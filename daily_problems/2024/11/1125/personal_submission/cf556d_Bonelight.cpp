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
#define MAT vector<vector<int>> 

class UnionFind{
    public:
        vector<int> X, fa_sz; // +fa -sz
        
        int find(int o){
            if(fa_sz[o] < 0) return o;
            return fa_sz[o] = find(fa_sz[o]);
        }

        UnionFind(int n): X(n), fa_sz(n,-1){
            iota(begin(X), end(X),0);
        }

        void merge(int xx, int yy){
            int x = find(xx), y = find(yy);
            if(x == y) return;
            fa_sz[y] += fa_sz[x];
            fa_sz[x] = y;
        }

        int size(int o){
            return -fa_sz[find(o)];
        }


};

/*希望残酷的世界还能为我这样的蝼蚁留下一丝美好*/
void solve(){
    int n,q; cin >> n >> q;
    UnionFind dsu1(n+1), dsu2(n+1);

    while(q --){
        int op,x,y; 
        cin >> op >> x >> y;

        if(op == 1){
            dsu1.merge(x,y);
        }

        if(op == 2){
            while(dsu2.find(x) < y){
                x = dsu2.find(x);
                dsu1.merge(x,x+1);
                dsu2.merge(x,x+1);
            }
        }

        if(op == 3){
            if(dsu1.find(x) == dsu1.find(y)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1; //cin >> T;
    while(T --){
        solve();
    } 
}
