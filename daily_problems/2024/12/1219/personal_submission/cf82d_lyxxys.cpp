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
    using ary2 = array<int,2>;
    const int inf = 2e9;

    int n;
    cin >> n;
    vector <int> A(n);
    for (auto &x : A) cin >> x;
    vector<vector<int>> f(n+1, vector<int>(n+1, inf));
    vector<vector<ary2>> chose(n+1, vector<ary2>(n+1)), pre(n+1, vector<ary2>(n+1));

    f[0][0] = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j <= i; ++ j){
            if (f[i][j] == inf) continue;
            int &cur = f[i][j];
            if (j == 0){
                if (i+1 == n){  // f[n-1][0] -> f[n][0]
                    if (cur+A[i] < f[i+1][0]){
                        f[i+1][0] = cur+A[i];
                        chose[i+1][0] = {i+1, -1};
                        pre[i+1][0] = {i, j};
                    }
                } else {
                    if (i+2 <= n){  // f[i][0] -> f[i+2][0]
                        int val = max(A[i], A[i+1]);
                        if (cur+val < f[i+2][0]){
                            f[i+2][0] = cur + val;
                            chose[i+2][0] = {i+1, i+2};
                            pre[i+2][0] = {i, j};
                        }
                    }
                    if (i+3 <= n){  // f[i][0] -> f[i+3][nxt] | nxt = i+1, i+2, i+3
                        vector <int> g = {i+1, i+2, i+3};  // 3个挑选2个
                        for (int u = 0; u < 3; ++ u){
                            int &nxt = g[u];
                            int val = 0;
                            vector <int> lst;
                            for (int t = 0; t < 3; ++ t){
                                if (u != t){
                                    fmax(val, A[g[t]-1]);
                                    lst.push_back(g[t]);
                                }
                            }

                            if (cur+val < f[i+3][nxt]){
                                f[i+3][nxt] = cur + val;
                                assert(lst.size() == 2);
                                chose[i+3][nxt] = {lst[0], lst[1]};
                                pre[i+3][nxt] = {i, j};
                            }
                        }
                    }
                }
            } else {
                if (i+1 <= n){  // f[i][j] -> f[i+1][0] | j != 0
                    int val = max(A[i], A[j-1]);
                    if (cur+val < f[i+1][0]){
                        f[i+1][0] = cur + val;
                        chose[i+1][0] = {j, i+1};
                        pre[i+1][0] = {i, j};
                    }
                }
                if (i+2 <= n){
                    vector <int> g = {j, i+1, i+2};  // 3个挑选2个
                    for (int u = 0; u < 3; ++ u){
                        int &nxt = g[u];
                        int val = 0;
                        vector <int> lst;
                        for (int t = 0; t < 3; ++ t){
                            if (u != t){
                                fmax(val, A[g[t]-1]);
                                lst.push_back(g[t]);
                            }
                        }

                        if (cur+val < f[i+2][nxt]){
                            f[i+2][nxt] = cur + val;
                            assert(lst.size() == 2);
                            chose[i+2][nxt] = {lst[0], lst[1]};
                            pre[i+2][nxt] = {i, j};
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++ i){
        int &cur = f[n][i];
        if (cur == inf) continue;
        int val = A[i-1];
        if (cur+val < f[n][0]){
            f[n][0] = cur+val;
            chose[n][0] = {i, -1};
            pre[n][0] = {n, i};
        }
    }

    int x = n, y = 0;
    vector <ary2> ans;
    while (x > 0){
        auto &j = pre[x][y];
        ans.push_back(chose[x][y]);
        x = j[0], y = j[1];
    }
    reverse(ans.begin(), ans.end());


    int m = ans.size();
    assert(m == (n+1)/2);
    cout << f[n][0] << "\n";
    for (int i = 0; i < m; ++ i){
        cout << ans[i][0];
        if (ans[i][1] != -1){
            cout << " " << ans[i][1];
        }
        cout << "\n";
    }
}
