#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 200050;
struct dsu {
    vector <int> p;
    vector<vector<int>> blo;
    dsu(){}
    dsu(int n): p(n+1), blo(n+1){
        for (int i = 0; i <= n; ++ i) blo[i].push_back(i), p[i] = i;
    }
    bool same(int x, int y){
        return root(x) == root(y);
    }
    int root(int x){
        return p[x] = x==p[x] ? x : root(p[x]);
    }
    void merge(int x, int y){
        x = root(x), y = root(y);
        if (x == y) return;
        if (blo[x].size() < blo[y].size()) swap(x, y);
        for (auto &it : blo[y])
            blo[x].push_back(it);
        p[y] = x;
    }
    void print(int x){
        x = root(x);
        for (auto &y : blo[x]) cout << y << " ";
    }
};


void solve(){
    int n;
    cin >> n;
    static dsu Y(n);
    for  (int i = 0; i < n-1; ++ i){
        int x, y;
        cin >> x >> y;
        Y.merge(x, y);
    }
    Y.print(1);
    cout << "\n";
}
