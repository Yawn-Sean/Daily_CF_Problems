#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}
vector <char> cken;

void init(){
    for (int i = 0; i < 10; ++ i) cken.push_back(i+'0');
    for (int i = 0; i < 26; ++ i) cken.push_back(i+'a');
    for (int i = 0; i < 26; ++ i) cken.push_back(i+'A');
}
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector <string> s(n), res(n);
    int c = 0;
    for (int i = 0; i < n; ++ i){
        cin >> s[i];
        for (auto &ch : s[i]){
            c += ch == 'R';
        }
    }
    vector <int> tmps;
    for (int i = 0; i < c%k; ++ i){
        tmps.push_back(c/k + 1);
    }
    while (tmps.size() < k) tmps.push_back(c/k);

    int jt = 0;
    for (int i = 0, all = 0; i < n; ++ i){
        if (i%2==0){
            for (int j = 0; j < m; ++ j){
                if (s[i][j] == 'R') all += 1;
                res[i] += cken[jt];

                if (all == tmps[jt]){
                    all = 0;
                    if (jt < k-1) jt += 1;
                }
            }
        } else {
            for (int j = m-1; j >= 0; -- j){
                if (s[i][j] == 'R') all += 1;
                res[i] += cken[jt];

                if (jt < k && all == tmps[jt]){
                    all = 0;
                    if (jt < k-1) jt += 1;
                }
            }
            reverse(res[i].begin(), res[i].end());
        }
    }

    for (int i = 0; i < n; ++ i){
        cout << res[i] << "\n";
    }
}
