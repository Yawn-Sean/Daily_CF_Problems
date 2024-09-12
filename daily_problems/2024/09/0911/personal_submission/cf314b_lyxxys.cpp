#include <bits/stdc++.h>
using namespace std;
const int N = 15000000;

void solve(){
    int b, d;
    string a, c;
    cin >> b >> d;
    cin >> a >> c;
    int m = c.size();

    vector <int> cnt(m), p(m);
    iota(p.begin(), p.end(), 0);
    for (int i = 0; i < m; ++ i){
        for (auto &ch : a){
            if (ch == c[p[i]]){
                p[i] += 1;
                if (p[i] == m){
                    p[i] = 0;
                    cnt[i] += 1;
                }
            }
        }
    }

    int res = 0, cur = 0;
    for (int i = 0; i < b; ++ i){
        res += cnt[cur];
        cur = p[cur];
    }
    cout << res/d << "\n";
}

