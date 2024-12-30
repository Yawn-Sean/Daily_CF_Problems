#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100, inf = 0x3f3f3f3f, P = 998244353;

/*
给你两个字符串s, t，以及m个将一个字符转化为另一个字符的代价的方式。
求让 s和t相同 的最小代价
*/
void solve(){
    string s, t;
    cin >> s >> t;
    int m;
    cin >> m;

    if (s.size() != t.size())
        return cout << -1 << "\n", void();
    
    vector<vector<int>> dis(100, vector<int>(100, inf));
    for (int i = 0; i < 26; ++ i) dis[i][i] = 0;
    while (m--){
        char a, b;
        int w;
        cin >> a >> b >> w;
        int c1 = a-'a', c2 = b-'a';
        dis[c1][c2] = min(dis[c1][c2], w);
    }
    for (int k = 0; k < 26; ++ k)
        for (int i = 0; i < 26; ++ i)
            for (int j = 0; j < 26; ++ j)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
    
    vector<vector<int>> chs(100, vector<int>(100)), f(100, vector<int>(100, inf));
    // f[c1][c2] 表示 使得两个字符 c1,c2相等的最小代价
    for (int i = 0; i < 26; ++ i)
        for (int j = 0; j < 26; ++ j)
            for (int k = 0; k < 26; ++ k)
                if (f[i][j] > dis[i][k]+dis[j][k]){
                    f[i][j] = dis[i][k]+dis[j][k];
                    chs[i][j] = k;
                }
    
    int res = 0;
    string ans;

    for (int i = 0; i < s.size(); ++ i){
        if (s[i]==t[i]){
            ans += s[i];
        } else {
            int c1 = s[i]-'a', c2 = t[i]-'a';
            if (f[c1][c2] == inf) return cout << -1 << "\n", void();
            res += f[c1][c2], ans += char(chs[c1][c2]+'a');
        }
    }
    cout << res << "\n" << ans << "\n";
}

