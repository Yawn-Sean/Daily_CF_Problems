#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 500, mod = 1e9 + 7, inf = 1e9;

void solve(){
    int n;
    string s, t;
    cin >> n >> s >> t;
    s = " " + s, t = " " + t;
    
    vector<array<int,2>> ans;
    /*
        按情况分类讨论，时间复杂度O(n^2)
    */
    for (int i = 1; i <= n; ++ i){
        if (s[i] == t[i]) continue;
        bool flg = 0;
        for (int j = i+1; j <= n; ++ j){
            if (s[i] == s[j]){
                swap(s[j], t[i]);
                ans.push_back({j, i}), flg = 1;
                break;
            }
        }
        if (flg) continue;
        for (int j = i+1; j <= n; ++ j){
            if (s[i] == t[j]){
                swap(s[i], t[i]), swap(s[i], t[j]);
                ans.push_back({i, i}), ans.push_back({i, j});
                flg = 1;
                break;
            }
        }
        if (flg) continue;
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    cout << ans.size() << "\n";
    for (auto &it : ans){
        cout << it[0] << " " << it[1] << "\n";
    }
}
