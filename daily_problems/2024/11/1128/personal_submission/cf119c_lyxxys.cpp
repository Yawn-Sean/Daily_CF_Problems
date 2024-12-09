#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    using ary2 = array<long long,2>;
    using ary4 = array<long long,4>;
    const long long inf = 1e18;

    const int N = 101;
    static long long f[N][N][N]; // f[i][j][k] 最后一次选了科目i，第j次选，且当前训练量是 k+A[i][0] 一共选的科目训练量求和的最大值
    static ary2 pre[N][N][N];

    int n, m, k;
    cin >> n >> m >> k;
    vector <ary4> A(m);
    for (int i = 0; i < m; ++ i){
        auto &it = A[i];
        cin >> it[0] >> it[1] >> it[2];
        it[3] = i+1;
        assert(it[1]-it[0] <= 100);
    }

    sort(A.begin(), A.end(), [&](auto &u, auto &v){
        return u[2] < v[2];
    });

    for (int i = 0; i < m; ++ i){
        for (int j = 1; j < N; ++ j){
            for (int d = 0, det=A[i][1]-A[i][0]; d <= det; ++ d){
                if (j > 1) f[i][j][d] = -inf;
                else f[i][j][d] = d + A[i][0];
            }
        }
    }

    for (int i1 = 0; i1 < m; ++ i1){ // i1 枚举最后一次选的科目
        auto &t1 = A[i1];
        for (int j = 2; j <= n; ++ j){  // j 枚举一共选了多少个
            for (int u = 0, det=t1[1]-t1[0]; u <= det; ++ u){  // u 枚举当前科目的偏移量
                for (int i2 = i1-1; i2 >= 0; -- i2){  // i2 枚举前驱 科目
                    auto &t2 = A[i2]; 
                    if (t2[2] == t1[2]) continue;  // ci 严格递增
                    assert(t2[2] < t1[2]);

                    long long cur = u+t1[0];

                    if (cur-k >= t2[0] && cur-k <= t2[1]){
                        int v = cur-k-t2[0];
                        auto &fj = f[i2][j-1][v];
                        if (fj != -inf && f[i1][j][u] < fj+cur){
                            f[i1][j][u] = fj+cur;
                            pre[i1][j][u] = {i2, v};
                        }
                    }

                    if (cur%k == 0 && cur/k >= t2[0] && cur/k <= t2[1]){
                        int v = cur/k - t2[0];
                        auto &fj = f[i2][j-1][v];
                        if (fj != -inf && f[i1][j][u] < fj+cur){
                            f[i1][j][u] = fj+cur;
                            pre[i1][j][u] = {i2, v};
                        }
                    }
                }
            }
        }
    }

    
    long long Max = -inf;
    ary2 chose;
    for (int i = 0; i < m; ++ i){
        auto &t1 = A[i];
        for (int u = 0, det=t1[1]-t1[0]; u <= det; ++ u){  // 枚举所有科目 一共选n个时 的最大值，只有合法时(不等于-inf)才选
            if (f[i][n][u] > Max){
                Max = f[i][n][u];
                chose = {i, u};
                assert(Max > 0);
            }
        }
    }
  
    if (Max == -inf){
        cout << "NO" << "\n";
    } else {
        cout << "YES\n";
        vector <ary2> ans;
        int i = chose[0], j = n, d = chose[1];
        while (j > 0){
            ans.push_back({A[i][3], d+A[i][0]});
            auto &t = pre[i][j][d];
            i = t[0], d = t[1], j -= 1;
        }
        reverse(ans.begin(), ans.end());
        for (auto &it : ans){
            cout << it[0] << " " << it[1] << "\n";
        }
    }
}
