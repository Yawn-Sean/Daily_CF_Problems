#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
using u64 = unsigned long long;
const f64 eps = 1e-12;
const i64 inf_i64 = 4e18;
const int inf_int = 2e9;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
template <class T> void print(vector <T> &A){
    int n = A.size();
    for (int i = 0; i < n; ++ i){
        if (i) cout << " ";
        cout << A[i]+1;
    }
    cout << "\n";
}
int jgs(f64 x){
    return x < -eps ? -1 : x > eps;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector <int> A(n), pk(n);
    for (auto &x : A){
        cin >> x;
    }

    for (int i = 0,u,v; i < n-1; ++ i){
        cin >> u >> v;
        u -= 1, v -= 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector <int> ans = {0};
    auto chge = [&](int i)->void{
        A[i] = -A[i];
        ans.push_back(i);
    };

    auto dfs_find = [&](auto &&self, int u, int presor)->void{
        if (u != 0){
            chge(u);
        }
        for (auto &v : g[u]){
            if (v == presor) continue;
            self(self, v, u);
        }
        if (u != 0){
            chge(presor);
        }
        if (A[u] != 1){
            if (u){
                chge(u), chge(presor);
            } else {
                int v = g[u][0];
                chge(v), chge(u), chge(v);
            }
        }
    };
    dfs_find(dfs_find, 0, -1);

    print(ans);
}

int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
#else
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int _ = 1;
    while (_--) solve();
    return 0;
}
