#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    auto error = [&]()->void{
        cout << -1 << "\n";
    };

    using ary2 = array<int,2>;
    using ll = long long;
    const ll inf = 1e18;

    int n, m;
    cin >> n >> m;
    vector <int> A(n);
    vector <ll> Aby;
    for (auto &x : A) cin >> x;
    vector<vector<int>> path(n), gp(n);
    vector<ary2> gs;

    for (int i = 0; i < m; ++ i){
        int e, t, p;
        cin >> e >> t >> p;
        e -= 1;
        gs.push_back({t,p});
        gp[e].push_back(i);
    }

    for (int i = 0; i < n; ++ i){
        auto &g = gp[i];  //哪一组选择
        int len = g.size();
        vector<vector<ll>> f(len+1, vector<ll>(101, inf));  // 前 i 个选择使得价值是 j 的最小花费
        vector<vector<ary2>> last(len+1, vector<ary2>(101));  // 记录上一个状态
        vector<vector<int>> chose(len+1, vector<int>(101));   // 记录这种状态选择了什么

        f[0][0] = 0;

        for (int i = 0; i < len; ++ i){
            auto &gi = gs[g[i]];  // 找到是哪一个选择
            f[i+1] = f[i];
            chose[i+1] = chose[i];
            last[i+1] = last[i];

            for (int j = 0; j <= 100; ++ j){
                int nxt = min(100, j+gi[1]);
                if (f[i][j]+gi[0] < f[i+1][nxt]){
                    f[i+1][nxt] = f[i][j]+gi[0];
                    last[i+1][nxt] = {i, j};
                    chose[i+1][nxt] = g[i];  // 第 g[i]+1 个选择
                }
            }
        }

        if (f[len][100] >= inf) return error();
        int cr1 = len, cr2 = 100;
        while (cr2 > 0){
            auto &it = last[cr1][cr2];
            path[i].push_back(chose[cr1][cr2]+1);
            cr1 = it[0], cr2 = it[1];
        }
        Aby.push_back(f[len][100]);
    }

    long long cur = 0;
    for (int i = 0; i < n; ++ i){
        cur += Aby[i];
        if (cur > A[i]) return error();
    }

    vector <int> ans;
    for (int i = 0; i < n; ++ i){
        for (auto &x : path[i]){
            ans.push_back(x);
        }
    }

    int len = ans.size();
    cout << len << "\n";
    for (int i = 0; i < len; ++ i){
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}
