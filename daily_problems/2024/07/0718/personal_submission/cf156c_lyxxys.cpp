#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 500, mod = 1e9 + 7, inf = 1e9;
/*
    字符串问题 转化为 序列问题
    f[i][j]表示前 i 个数字且和为j的方案数量
*/
void solve(){
    vector <vector<int>> f(101, vector<int>(2700));
    f[0][0] = 1;
    for (int i = 1; i <= 100; ++ i){
        for (int j = 1; j <= 26*i; ++ j){
            for (int p = 1; p <= 26 && p <= j; ++ p){
                f[i][j] += f[i-1][j-p], f[i][j] %= mod;
            }
        }
    }

    int m;
    cin >> m;
    while (m--){
        string s;
        cin >> s;
        int sum = 0;
        for (auto &ch : s) sum += ch-'a'+1;
        int u = s.size();
        cout << (f[u][sum]-1+mod)%mod << "\n";
    }
}
