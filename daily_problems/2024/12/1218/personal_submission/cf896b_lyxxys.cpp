#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    int n, m, c;
    cin >> n >> m >> c;
    const int limi = c/2;

    vector <int> ans(n+1, -1);
    for (int i = 0; i < m; ++ i){
        int x, pos = -1;
        cin >> x;
        if (x <= limi){
            for (int j = 1; j <= n; ++ j){
                if (ans[j] == -1 || x < ans[j]){
                    pos = j;
                    break;
                }
            }
        } else {
            for (int j = n; j >= 1; -- j){
                if (ans[j] == -1 || x > ans[j]){
                    pos = j;
                    break;
                }
            }
        }
        assert(pos != -1);
        ans[pos] = x;
        cout << pos << "\n" << flush;
        bool jg = 1;
        for (int j = 1; j <= n; ++ j){
            if (ans[j] < ans[j-1] || ans[j] == -1){
                jg = 0;
                break;
            }
        }
        if (jg) break;
    }
}
