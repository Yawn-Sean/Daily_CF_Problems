#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9, mod = 998244353, N = 100060;
int f[505][505][505], ne[505]; //f[i][j][k] 表示在a串中的前i个位置，b串匹配到位置j，且已经匹配了k个字符串b的最小代价
int tran[505][2];

void init(string a){
    int n = a.size();
    if (a[1] == '0') tran[0][0] = 1;
    else tran[0][1] = 1;
    a += " ", ne[0] = -1;
    for (int i = 1, j; i < n; ++ i){
        j = ne[i-1];
        while (j != -1 && a[j+1] != a[i]) j = ne[j];
        ne[i] = j+1;
        tran[i][0] = a[i+1]=='0' ? i+1 : tran[ne[i]][0];
        tran[i][1] = a[i+1]=='1' ? i+1 : tran[ne[i]][1];
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    a = " " + a, b = " " + b;
    init(b);
    memset(f, 0x3f, sizeof f);
    f[0][0][0] = 0;
    for (int i = 1; i <= n; ++ i)
        for (int j = 0; j <= m; ++ j)
            for (int k = 0; k <= n-m; ++ k)
                for (int t = 0; t <= 1; ++ t){
                    int u = tran[j][t], v = k+(u==m);
                    f[i][u][v] = min(f[i][u][v], f[i-1][j][k] + (a[i]-'0'!=t));
                }

    for (int i = 0; i <= n-m+1; ++ i){
        int res = n+1;
        for (int j = 0; j <= m; ++ j) res = min(res, f[n][j][i]);
        if (res == n+1) res = -1;
        cout << res << " ";
    }
    cout << "\n";
}
