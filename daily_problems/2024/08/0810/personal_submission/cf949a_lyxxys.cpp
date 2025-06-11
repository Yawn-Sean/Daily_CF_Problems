#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 5050, mod = 1e9+7, inf = 1e9;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vector<vector<int>> res(n);

    int cur = 0, Max = 0;
    for (int i = 1; i <= n; ++ i){
        if (s[i] == '0') res[cur++].push_back(i);
        else {
            if (!cur){
                cout << -1 << "\n";
                return;
            }
            res[--cur].push_back(i);
        }
        Max = max(Max, cur);
    }

    if (cur != Max){
        cout << -1 << "\n";
        return;
    }
    cout << cur << "\n";
    for (int i = 0; i < cur; ++ i){
        cout << res[i].size() << " ";
        for (auto &x : res[i]) cout << x << " ";
        cout << "\n";
    }
}
