#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1000500, inf = 1e9;
struct dsu {
    vector <int> p;
    dsu(){}
    dsu(int n): p(n+1){
        iota(p.begin(), p.end(), 0);
    }
    int root(int x){
        return p[x] = p[x] == x ? x : root(p[x]);
    }
    void merge(int x, int y){
        x = root(x), y = root(y);
        if (x == y) return;
        p[y] = x;
    }
    int count(int x, int y){
        int cnt = 0;
        for (int i = x; i <= y; ++ i)
            if (p[i] == i) ++ cnt;
        return cnt;
    }
};
dsu unis(4*N);

void solve(){
    int n, m;
    cin >> n >> m;
    auto getid = [&](int x, int y)->int{
        if (x==1) return y;
        if (x==n) return m + 2*(n-2) + y;
        if (y==1) return m + 2*(x-1) - 1;
        if (y==m) return m + 2*(x-1);
    };
    if (n < m) swap(n, m);
    int up = 2*(n+m)-4;
    // cout << getid(2,1) << "\n";
    // 枚举每一行
    // return;
    for (int i = 1; i <= n; ++ i){
        //一行四条线
        if (i <= m){
            unis.merge(getid(i,1),getid(1,i));
            unis.merge(getid(i,m),getid(1,m-i+1));
        } else {
            unis.merge(getid(i,1),getid(i-m+1,m));
            unis.merge(getid(i,m),getid(i-m+1,1));
        }

        if (i+m-1 < n){
            unis.merge(getid(i,1),getid(m+i-1,m));
            unis.merge(getid(i,m),getid(m+i-1,1));
        } else {
            unis.merge(getid(i,1),getid(n,n-i+1));
            unis.merge(getid(i,m),getid(n,m-n+i));
        }
    }

    cout << unis.count(1, up) << "\n";
}
