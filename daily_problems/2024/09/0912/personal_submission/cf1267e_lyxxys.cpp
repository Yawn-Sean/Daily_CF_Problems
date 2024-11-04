#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 15000000;
 
void solve(){
    int n, m;
    cin >> m >> n;
    vector <vector<int>> Ele(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            cin >> Ele[i][j];
        }
    }
 
    vector <vector<int>> ans(m);
    int cur = 0;
    for (int i = 1; i < m; ++ i){
        vector <int> p(n);
        int sum = 0;
        for (int j = 1; j <= n; ++ j) sum += Ele[j][m] - Ele[j][i];
        iota(p.begin(), p.end(), 1);
        sort(p.begin(), p.end(), [&](int x, int y){
            return (Ele[x][m]-Ele[x][i]) > (Ele[y][m]-Ele[y][i]);
        });
        if (sum <= 0){
            cur = i;
            break;
        }
        for (int j = 0; j < n && sum > 0; ++ j){
            int pj = p[j];
            sum -= Ele[pj][m] - Ele[pj][i];
            ans[i].push_back(pj);
        }
        
        if (cur == 0 || ans[i].size() < ans[cur].size()) cur = i;
    }
 
    cout << ans[cur].size() << "\n";
    if (ans[cur].size()){
        for (auto &x : ans[cur]) cout << x << " ";
        cout << "\n";
    }
}
 
