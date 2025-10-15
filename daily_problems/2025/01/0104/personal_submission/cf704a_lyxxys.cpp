#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
const f64 eps = 1e-12;
const i64 inf_i64 = 1e18;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
int jgs(f64 x){
    return (x < -eps ? -1 : x >= eps);
}

void solve(){
    int n, q;
    cin >> n >> q;
    vector<vector<int>> locs(n);
    vector <int> Q(q), vis(q), who(q);
    int lo = 0, hi = -1;

    vector <int> ans;
    
    int cur = 0, tot = 0;
    for (int i = 0; i < q; ++ i){
        int type, x;
        cin >> type >> x;
        if (type == 1){
            x -= 1;
            cur += 1;
            locs[x].push_back(i);
            Q[++ hi] = i;
            who[i] = ++ tot;
        } else if (type == 2){
            x -= 1;
            while (locs[x].size()){
                int j = locs[x].back();
                if (!vis[j]){
                    cur -= 1;
                    vis[j] = 1;
                }
                locs[x].pop_back();
            }
        } else {
            while (lo <= hi && who[Q[lo]] <= x){
                int j = Q[lo++];
                if (!vis[j]){
                    cur -= 1;
                    vis[j] = 1;
                }
            }
        }

        assert(cur >= 0);
        ans.push_back(cur);
    }

    for (auto &x : ans){
        cout << x << "\n";
    }
}
