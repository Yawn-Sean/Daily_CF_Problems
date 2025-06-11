#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    using ld = long double;

    int n, m;
    cin >> n >> m;
    vector <int> row(n+1), col(n+1);
    int c1 = n, c2 = n;
    for (int i = 0,x,y; i < m; ++ i){
        cin >> x >> y;
        if (!row[x]) row[x] = 1, c1 -= 1;
        if (!col[y]) col[y] = 1, c2 -= 1;
    }

    vector<vector<ld>> f(c1+2, vector<ld>(c2+2));
    // f[i][j] 表示从 染了 i 行 j 列 的 状态出发，到染了 c1 行 c2 列 状态的 期望步数
    // 当 i 和 j 越小时，新增一行与新增一列 这件事发生概率就会尽可能大
    // f[c1][c2] = 0
    
    for (int i = c1; i >= 0; -- i){
        for (int j = c2; j >= 0; -- j){
            if (i == c1 && j == c2) continue;
            f[i][j] += n*n + (c1-i)*(c2-j)*f[i+1][j+1] + (c1-i)*(n-c2+j)*f[i+1][j] + (n-c1+i)*(c2-j)*f[i][j+1];
            f[i][j] /= (n*n - (n-c1+i)*(n-c2+j));
        }
    }

    cout << fixed << setprecision(15) << f[0][0] << "\n";
}
