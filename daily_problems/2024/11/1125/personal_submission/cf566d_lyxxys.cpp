#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n, q;
    cin >> n >> q;
    vector <int> p1(n+1), p2(n+1);
    for (int i = 1; i <= n; ++ i){
        p1[i] = p2[i] = i;
    }
    auto find = [&](vector<int>&p, int x)->int{
        int rt = x;
        while (p[rt] != rt) rt = p[rt];
        while (p[x] != rt){
            int &y = p[x];
            x = y, y = rt;
        }
        return rt;
    };
    auto same = [&](int x, int y)->bool{
        return find(p1, x) == find(p1, y);
    };
    auto merge = [&](int x, int y)->void{
        int x1 = find(p1, x), y1 = find(p1, y);
        if (x1 == y1) return;
        p1[y1] = x1; 
    };

    for (int i = 0; i < q; ++ i){
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1){
            merge(x, y);
        } else if (type == 2){
            assert(x <= y);
            int r = find(p2, x);
            while (r < y){
                int j = find(p2, r+1);   // 第二个并查集往右合并, 第一个并查集精确代表集合关系
                merge(r, j), p2[r] = j;
                r = j;
            }
        } else {
            if (same(x, y)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
