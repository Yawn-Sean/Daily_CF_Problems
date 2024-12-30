#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

template <class T> struct Mat {
    vector<vector<T>> g;
    int n, m;
    Mat(){}
    Mat(int n, int m): n(n), m(m), g(n, vector<T>(m)) {}
    Mat(vector<vector<T>> g): n(g.size()), m(g[0].size()), g(g) {}
    Mat operator*(Mat oth){
        assert(m == oth.g.size());
        int M = oth.g[0].size();
        vector<vector<T>> res(n, vector<T>(M));
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < M; ++ j){
                for (int k = 0; k < m; ++ k){
                    res[i][j] += g[i][k] * oth.g[k][j];
                }
            }
        }
        return Mat(res);
    }
    void show(){
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
                cout << g[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

void solve(){
    using mat = Mat<long double>;

    auto pows = [&](mat A, mat B, int b)->mat{
        assert(b >= 0);
        int cnt = 0;
        while (b){
            if (b&1) A = A*B;
            B = B*B;
            b >>= 1;
        }
        return A;
    };

    int n, hi;
    cin >> n >> hi;
    vector <long double> pros(128);
    for (int i = 0; i <= hi; ++ i) cin >> pros[i];

    mat A(1, 128), B(128, 128);
    for (int i = 0; i <= hi; ++ i) A.g[0][i] = pros[i];
    for (int i = 0; i < 128; ++ i){
        for (int j = 0; j < 128; ++ j){
            B.g[i][j] = pros[i^j];
        }
    }

    auto res = pows(A, B, n-1);
    cout << fixed << setprecision(15) << (1.0 - res.g[0][0]) << "\n";
}
