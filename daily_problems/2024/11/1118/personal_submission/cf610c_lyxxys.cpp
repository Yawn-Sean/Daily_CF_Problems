#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int k;
    cin >> k;
    if (!k){
        cout << "+\n";
        return;
    }
    vector <string> res = {{"++"},{"+*"}};

    auto anti = [&](char c)->char{
        return c == '+' ? '*' : '+';
    };
    auto tform = [&](string s)->string{
        for (auto &ch : s) ch = anti(ch);
        return s;
    };

    k -= 1;
    int base = 1;
    while (k--){
        base *= 2;

        vector <string> tmps;
        for (int i = 1; i < res.size(); ++ i){
            tmps.push_back(res[i] + tform(res[i]));
            res[i] += res[i];
        }

        for (auto &j : tmps) res.push_back(j);

        string t(base, '+'), by(base, '*');
        res[0] += t;
        t += by;

        res.push_back(t);
    }

    assert(res.size() == base*2);
    for (auto &ans : res) cout << ans << "\n";
}
