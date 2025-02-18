#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1e7, mod = 1e9+7, inf = 1e9;

void solve(){
    int n, k;
    cin >> n >> k;
    vector <vector<int>> g(n+1);

    queue <array<int,2>> Q;
    for (int i = 2; i <= k+1; ++ i){
        g[1].push_back(i);
        Q.push({i, 1});
    }
    int Max1 = 1, Max2 = 1;
    int tot = k+2;
    while (tot <= n){
        auto [x, d] = Q.front();
        Q.pop();
        g[x].push_back(tot);
        Q.push({tot, d+1});
        if (d+1 > Max1){
            Max2 = Max1, Max1 = d+1;
        } else if (d+1 > Max2) Max2 = d+1;
        tot += 1;
    }
    cout << Max1+Max2 << "\n";

    for (int i = 1; i <= n; ++ i){
        for (auto &y : g[i]) cout << i << " " << y << "\n";
    }
}
