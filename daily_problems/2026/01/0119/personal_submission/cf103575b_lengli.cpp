#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    int n;
    vector<int> p, sz;
    UnionFind(int n): n(n), p(n), sz(n,1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    bool merge(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return false;
        if(sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> us(m), vs(m), ws(m);
    for(int i = 0; i < m; ++i){
        cin >> us[i] >> vs[i] >> ws[i];
        --us[i]; --vs[i];
    }

    UnionFind uf1(n), uf2(n);

    for(int i = 0; i < m; ++i){
        if(ws[i] % 2 == 0){
            uf1.merge(us[i], vs[i]);
        }
    }

    vector<int> used(m, 0);
    int even = 1;

    for(int i = 0; i < m; ++i){
        if(ws[i] % 2 == 1 && uf1.merge(us[i], vs[i])){
            uf2.merge(us[i], vs[i]);
            used[i] = 1;
            even ^= 1;
        }
    }

    if(!even){
        for(int i = 0; i < m; ++i){
            if(ws[i] % 2 == 1 && !used[i] && uf2.merge(us[i], vs[i])){
                used[i] = 1;
                even ^= 1;
                break;
            }
        }
    }

    if(!even){
        cout << "NO\n";
        return 0;
    }

    for(int i = 0; i < m; ++i){
        if(ws[i] % 2 == 0 && uf2.merge(us[i], vs[i])){
            used[i] = 1;
        }
    }

    cout << "YES\n";
    bool first = true;
    for(int i = 0; i < m; ++i){
        if(used[i]){
            if(!first) cout << ' ';
            cout << i + 1;
            first = false;
        }
    }
    cout << "\n";

    return 0;
}
