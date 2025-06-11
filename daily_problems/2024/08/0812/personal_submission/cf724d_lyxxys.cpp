#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 5050, mod = 1e9+7, inf = 1e9;
int vis[100050];
vector <int> Pos[26];
int sz[26];

void solve(){
    int m;
    string s;
    cin >> m >> s;
    int n = s.size();
    s = " " + s;
    set <int> seek = {n+1};
    for (int i = n; i >= 1; -- i){
        Pos[s[i]-'a'].push_back(i);
        ++ sz[s[i]-'a'];
        if (i <= n-m+1) seek.insert(i);
        else vis[i] = 1;
    }
    /*
        按字典序考虑每个字母，当字典序大的被选时，字典序小的一定都被选
        从后往前选一定最优
    */
    string res;
    int all = n-m+1;
    int p;
    for (int i = 0; i < 26 && all; ++ i){
        vector <int> tmps;
        for (auto &cur : Pos[i]){
            for (set<int>::iterator it = seek.lower_bound(cur-m+1); *it<=cur && all; it = seek.erase(it)){
                -- all;
                tmps.push_back(*it);
            }
        }
        if (all == 0){
            p = i;
            break;
        } else {
            for (auto &x : tmps) vis[x] = 1;
            while (sz[i]--) res += char(i+'a');
        }
    }
    for (int i = 1, lst = -1, j = 1; i <= n-m+1; ++ i){
        if (lst == -1 && !vis[i]) lst = i;
        if (s[i] == char(p+'a')) j = i;
        if (lst != -1 && (i-lst+1 == m || i == n-m+1)){
            res += char(p+'a');
            lst = -1;
            if (i == n-m+1) break;
            i = j;
        }
    }
    cout << res << "\n";
}
