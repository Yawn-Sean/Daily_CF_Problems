#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    const int inf = 1e9;
    int n, k;
    cin >> n >> k;
    vector <int> shot(n+1), suf1(n+2), suf2(n+2);
    vector<vector<int>> act(n+1, vector<int>(n+1));
    vector<vector<int>> f(n+3, vector<int>(n+3, inf));
    // f[i][j] 表示到达状态 j, i, i+1, i+2, ···, n 最少要多少枪, j = 0 表示不存在, j < i.
    // 为了表示只有一个人存活, 引入第 n+1 个人, f[n+1][0] 表示一个人都没有存活
    for (int i = 1; i <= n; ++ i){
        cin >> shot[i];
        shot[i] = (shot[i] == 100 ? 2 : (shot[i] > 0)); // 0,1,2 不能射杀、可能射杀、一定射杀
    }

    // suf1[i]: i 和它右边 有 >= 1的(i和它右边有射杀能力)     suf2[i]: i 和它右边全都 <= 1 (i和它右边不能有必杀能力)
    for (int i = n, j1=0, j2=1; i >= 1; -- i){
        if (shot[i] >= 1) j1 = 1;
        if (shot[i] == 2) j2 = 0;
        suf1[i] = j1, suf2[i] = j2;
    }
    suf2[n+1] = 1;

    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j < i; ++ j){
            int u1 = j==0 ? i : j;
            int u2 = j==0 ? i+1 : i;
            if (shot[u1] <= 1 && suf1[u2]) act[i][j] += 1<<0;  // 射杀 u1, u2存活
            if (shot[u1] >= 1 && suf2[u2]) act[i][j] += 1<<1;  // 射杀 u2  u1存活
            if (shot[u1] >= 1 && suf1[u2]) act[i][j] += 1<<2;  // 射杀 u1, u2
        }
    }
    
    f[1][0] = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j < i; ++ j){
            if (f[i][j] == inf) continue;
            int v = f[i][j];
            if ((act[i][j]>>0)&1){
                int nxt = (j==0 ? i+1 : i);
                fmin(f[nxt][0], v+1);
            }
            if ((act[i][j]>>1)&1){
                if (j == 0){
                    fmin(f[i+2][i], v+1);
                } else {
                    fmin(f[i+1][j], v+1);
                }
            }
            if ((act[i][j]>>2)&1){
                int nxt = (j==0 ? i+2 : i+1);
                fmin(f[nxt][0], v+1);
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n+1; ++ i){
        for (int j = 0; j < i; ++ j){
            if (f[i][j] <= k){
                res += 1;
            }
        }
    }

    if (f[n+1][n] <= k && f[n][0] <= k) res -= 1;
    assert(f[n+1][n] == inf);

    cout << res << "\n";
}
