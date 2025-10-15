#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector <array<int,3>> egs;
    vector <int> chose(n, -1);

    vector <int> stk;
    for (int i = 0; i < m; ++ i){
        int u, v, c;
        cin >> u >> v >> c;
        u -= 1, v -= 1;
        g[u].push_back(i);
        g[v].push_back(i);
        egs.push_back({u, v, c});
    }

    for (int i = 0; i < n; ++ i){
        if (chose[i] == -1){
            chose[i] = 0;
            vector <int > stk = {i};
            while (!stk.empty()){
                auto u = stk.back();
                stk.pop_back();
                for (auto &id : g[u]){
                    int v = egs[id][0]+egs[id][1] - u;
                    int c = egs[id][2];
                    if (c > 0){
                        if (chose[v] == -1){
                            chose[v] = chose[u];
                            stk.push_back(v);
                        } else if (chose[v] != chose[u]){
                            cout << "Impossible\n";
                            return;
                        }
                    } else {
                        if (chose[v] == -1){
                            chose[v] = !chose[u];
                            stk.push_back(v);
                        } else if (chose[u] == chose[v]){
                            cout << "Impossible\n";
                            return;
                        }
                    }
                }
            }
        }
    }

    vector <int> ans;
    for (int i = 0; i < n; ++ i){
        if (chose[i]){
            ans.push_back(i);
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++ i){
        if (i) cout << " ";
        cout << ans[i]+1;
    }
    cout << "\n";
}
