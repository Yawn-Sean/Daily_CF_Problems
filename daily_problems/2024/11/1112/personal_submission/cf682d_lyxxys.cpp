#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}
const int N = 1001;
int f[N][N][11][2];  // f[i][j][k] 表示 s 的前i个 和 b 的前j个最大匹配长度 第四维表示是否和上一段连接

void solve(){
    int n, m, L;
    cin >> n >> m >> L;
    string s, t;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;

    auto find = [&](int i, int j, int k)->int{
        return max(f[i][j][k][0], f[i][j][k][1]);
    };

    for (int k = 1; k <= L; ++ k){
        for (int i = 1; i <= n; ++ i){
            for (int j = 1; j <= m; ++ j){
                if (s[i] == t[j]){
                    f[i][j][k][1] = max(f[i-1][j-1][k][1], f[i-1][j-1][k-1][0]) + 1;
                }
                f[i][j][k][0] = max({find(i-1,j-1,k), find(i-1,j,k), find(i,j-1,k)});
            }
        }
    }

    int res = 1;
    for (int i = 1; i <= L; ++ i){
        fmax(res, find(n,m,i));
    }

    cout << res << "\n";
}
