#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
const f64 eps = 1e-12;
const i64 inf_i64 = 4e18;
const int inf_int = 1e9;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
int jgs(f64 x){
    return x < -eps ? -1 : x > eps;
}

void print(vector <int> &A){
    int n = A.size();
    for (int i = 0; i < n; ++ i){
        if (i) cout << " ";
        cout << A[i];
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> p(n), ps(n), f(n);
    vector<vector<int>> locs(n);
    for (int i = 0; i < n; ++ i){
        cin >> p[i];
        p[i] -= 1;
        ps[p[i]] = i;
    }
    for (int i = 0,u,v; i < m; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        if (ps[u] < ps[v]){
            locs[ps[u]].push_back(v);
        }
    }

    unordered_set <int> dels;
    for (int i = n-2; i >= 0; -- i){
        int cnt = dels.size() + locs[i].size();
        for (auto &x : locs[i]){
            if (dels.count(x)){
                cnt -= 1;
            }
        }
        assert(cnt <= n-i-1);
        if (cnt == n-i-1){
            dels.insert(p[i]);
        }
    }

    cout << dels.size() << "\n";
}
