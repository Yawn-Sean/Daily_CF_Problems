#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    int cnt = 0;
    for (auto &ch : s){
        cnt += ch == 'X';
    }

    auto find = [&](auto &&self, int u, int fill_x, int remain, bool lead)->int{
        if (u == n){
            return (lead || n == 1) && remain == 0;
        }
        if (u > 0 && !lead) return 0;

        int res = 0;
        if (s[u] == '_'){
            for (int i = 0; i < 10; ++ i){
                int nxt = (remain*10 + i) % 25;
                res += self(self, u+1, fill_x, nxt, lead|i);
            }
        } else if (s[u] == 'X'){
            int nxt = (remain*10 + fill_x) % 25;
            res += self(self, u+1, fill_x, nxt, lead|fill_x);
        } else {
            int nxt = (remain*10 + (s[u]-'0')) % 25;
            res += self(self, u+1, fill_x, nxt, lead|(s[u]-'0'));
        }

        return res;
    };

    const int limi = cnt ? 10 : 1;
    int res = 0;

    for (int i = 0; i < limi; ++ i){
        res += find(find, 0, i, 0, 0);
    }

    cout << res << "\n";
}
