#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 5050, mod = 1e9 + 7;
const double inf = 1e9;
double eps = 1e-10;

void solve(){
    map<string, unordered_set<string>> mps;
    unordered_set <int> infst;
    // stzero 对斜率为正无穷的特判
    int n;
    cin >> n;
    vector <array<int,2>> codi(n+1);
    for (int i = 1; i <= n; ++ i) cin >> codi[i][0] >> codi[i][1];

    auto tran = [](int x)->string{
        string res;
        int y = abs(x);
        while (y) res += char(y%10)+'0', y /= 10;
        reverse(res.begin(), res.end());
        if (x<0) res = "-"+res;
        return res;
    };

    ll tot = 0, minus = 0;
    for (int i = 2; i <= n; ++ i){
        for (int j = 1; j < i; ++ j){
            if (codi[i][0] == codi[j][0]){
                if (!infst.count(codi[i][0])){
                    minus += infst.size();
                    infst.insert(codi[i][0]);
                    ++ tot;
                };
            } else {
                int dx = codi[i][0]-codi[j][0], dy = codi[i][1]-codi[j][1];
                int d = __gcd(dx, dy);
                dx /= d, dy /= d;
                auto &mp = mps[tran(dy)+"#"+tran(dx)];
                int nume = codi[i][0]*codi[j][1] - codi[i][1]*codi[j][0];
                int deno = codi[i][0]-codi[j][0];
                d = __gcd(nume, deno);
                nume /= d, deno /= d;
                string t = tran(nume)+"#"+tran(deno);
                if (!mp.count(t)){
                    minus += mp.size();
                    mp.insert(t);
                    ++ tot;
                };
            }
        }
    }

    cout << (tot*(tot-1)/2) - minus << "\n";
}
