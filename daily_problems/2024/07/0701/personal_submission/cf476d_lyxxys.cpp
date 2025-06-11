#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+5, inf = 1e9;

void solve(){
    int n, k;
    cin >> n >> k;
    const int dx[] = {1,2,3,5};
    vector <vector<int>> res;
    for (int i = 0; i < n; ++ i){
        vector <int> ans;
        for (int j = 0; j < 4; ++ j)
            ans.push_back(k*(6*i + dx[j]));
        res.push_back(ans);
    }

    cout << k*(6*(n-1) + dx[3]) << "\n";
    for (auto &ans : res){
        for (auto &x : ans) cout << x << " ";
        cout << "\n";
    }
}
