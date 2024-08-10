#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 3e5+3, mod = 1e9 + 7, inf = 1e9;

void solve(){
    int n;
    cin >> n;
    vector<double> p(n+1);
    vector<vector<double>> mul(n+2, vector<double>(n+2, 1));

    for (int i = 1; i <= n; ++ i) cin >> p[i];
    sort(p.begin()+1, p.end());
    for (int i = 1; i <= n; ++ i){
        for (int j = i; j <= n; ++ j){
            if (i==j) mul[i][j] = (1-p[j]);
            else mul[i][j] = mul[i][j-1]*(1-p[j]);
        }
    }
    double res = 0;
    for (int i = n; i >= 1; -- i){
        double ans = 0;
        for (int j = i; j <= n; ++ j){
            ans += mul[i][j-1]*p[j]*mul[j+1][n];
        }
        res = max(res, ans);
    }

    cout << res << "\n";
}
