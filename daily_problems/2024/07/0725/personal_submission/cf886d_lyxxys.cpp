#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 4e5+10, mod = 1e9 + 7, inf = 1e9;
/*
    给出原串的部分子串(覆盖原串)，构造出原串使得 其所有子串出现的频率相同
*/
void solve(){
    int n;
    cin >> n;
    vector <int> vis(30), nexts(30, -1), deg(30);

    auto error = []()->void{
        cout << "NO\n";
    };

    while (n--){
        string s;
        cin >> s;
        int lst = -1;
        for (auto &ch : s){
            int c = ch-'a';
            if (vis[c] == n+1) return error();
            vis[c] = n+1;
            if (lst != -1){
                if (nexts[lst] != -1 && nexts[lst] != c) return error();
                nexts[lst] = c;
            }
            lst = c;
        }
    }
    // 有解情况一定是一条链
    string res;
    for (int i = 0; i < 26; ++ i){
        if (nexts[i] != -1){
            ++ deg[nexts[i]];
            if (deg[nexts[i]] > 1) return error();
        }
    }
    for (int i = 0; i < 26; ++ i){
        if (deg[i]==0 && vis[i]){
            vis[i] = 0;
            res += char(i+'a');
            int p = i;
            while (nexts[p] != -1){
                p = nexts[p];
                res += char(p+'a');
                vis[p] = 0;
            }
        }
    }

    for (int i = 0; i < 26; ++ i)
        if (vis[i]) return error();
    
    cout << res << "\n";

}
