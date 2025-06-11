#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    const int inf = 1e9;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> items(m);
    for (int i = 1,t,q; i <= n; ++ i){
        cin >> t >> q;
        items[m-t].push_back(q);
    }
    vector <int> f1(n+1, -inf), f2(n+1, -inf);
    f1[0] = 0, f1[1] = 0;
    for (int i = 0; i < m; ++ i){
        sort(items[i].begin(), items[i].end(), greater<int>());

        for (int j = 0; j <= n; ++ j){
            int cur = 0;
            for (int k = 0; k <= items[i].size(); ++ k){
                if (k > j) break;
                int nxt = min(n, 2*(j-k));
                fmax(f2[nxt], f1[j]+cur);
                if (k < items[i].size()){
                    cur += items[i][k];
                }
            }
        }
        for (int j = 0; j <= n; ++ j){
            f1[j] = f2[j], f2[j] = -inf;
        }
    }

    cout << *max_element(f1.begin(), f1.end()) << "\n";
}
