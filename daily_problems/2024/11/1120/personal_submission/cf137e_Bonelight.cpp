/*
    Bonelight * v *
    20241113：重 走 西 游
    千 仇 万 恨 无 归 处， 封 灯 何 须 至 尊 骨
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e18
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define VC vector<int>
#define MAT vector<VC>

class Fenwick{
    public: 
        vector<int> tr;
        int n;
        Fenwick(){}
        Fenwick(int n):n(n),tr(n+1,INF){}

        void add(int z, int v){
            for(int i = z; i <= n; i += i & -i) tr[i] = min(tr[i], v);
        }

        int get(int z){
            int res = INF;
            for(int i = z; i >= 1; i -= i&-i) res = min(res, tr[i]);
            return res;
        }
};

void solve(){   
    string s; cin >> s;
    for(auto &i:s) i = tolower(i);
    int n = s.size();
    s = " " + s;

    map<char,int> mp = {{'a',1},{'e',1},{'i',1},{'o',1},{'u',1}};
    Fenwick tr(1e6);

    vector<int> pre(n+1);
    for(int i = 1; i <= n; i ++){
        mp[s[i]]? pre[i]-- : pre[i]+=2;
        pre[i] += pre[i - 1];
    }

    vector<int> X;
    for(int i = 0; i <= n; i ++) X.push_back(pre[i]);
    sort(begin(X), end(X));
    X.erase(unique(begin(X),end(X)), end(X));
    auto id = [&](int o){return lower_bound(begin(X),end(X),o) - begin(X) + 1;};
    tr.add(id(0), 0);
    
    int ans = 0, num = 0;
    for(int i = 1; i <= n; i ++){
        int d = i - tr.get(id(pre[i]));
        if(d > ans) num = 1, ans = d;
        else if(d == ans) num ++;
        tr.add(id(pre[i]), i);
    }

    if(ans == 0) cout << "No solution" << endl;
    else cout << ans << ' ' << num << endl;
}

signed main(){
ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    // cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
