#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
const f64 eps = 1e-9;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    using ary2 = array<int,2>;
    vector <ary2> recs(3);

    auto chk = [&]()->int{
        vector <int> idx(3);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](auto &u, auto &v){
            return recs[u][1] > recs[v][1];
        });
        int i = idx[0], j = idx[1], k = idx[2];
        if (recs[i][1] == recs[j][1]+recs[k][1]){  // 0 长 1 宽
            if (recs[j][0] == recs[k][0] && recs[i][0]+recs[j][0] == recs[i][1]){
                return 1;
            }
        }
        if (recs[i][1] == recs[j][1] && recs[j][1] == recs[k][1]){
            if (recs[i][0]+recs[j][0]+recs[k][0] == recs[i][1]){
                return 2;
            }
        }
        return 0;
    };

    for (auto &it : recs){
        cin >> it[0] >> it[1];
    }

    int jg = 0;
    for (int i = 0; i < 8; ++ i){
        for (int j = 0; j < 3; ++ j){
            if (i>>j & 1){
                swap(recs[j][0], recs[j][1]);
            }
        }
        jg = chk();
        if (jg) break;
        for (int j = 0; j < 3; ++ j){
            if (i>>j & 1){
                swap(recs[j][0], recs[j][1]);
            }
        }
    }
    if (!jg) return void(cout << -1 << "\n");
    vector <int> idx(3);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](auto &u, auto &v){
        return recs[u][1] > recs[v][1];
    });
    int u1 = idx[0], u2 = idx[1], u3 = idx[2];
    const char cs[] = {'A', 'B', 'C'};
    vector<vector<char>> g(100, vector<char>(100, '?'));
    int siz = 0;
    if (jg == 1){
        siz = recs[u1][1];
        for (int i = 0; i < siz; ++ i){
            for (int j = 0; j < siz; ++ j){
                if (i < recs[u1][0]){
                    g[i][j] = cs[u1];
                } else if (j < recs[u2][1]){
                    g[i][j] = cs[u2];
                } else {
                    g[i][j] = cs[u3];
                }
            }
        }
    } else {
        siz = recs[u1][1];
        for (int i = 0; i < siz; ++ i){
            for (int j = 0; j < siz; ++ j){
                if (i < recs[u1][0]){
                    g[i][j] = cs[u1];
                } else if (i < recs[u1][0]+recs[u2][0]){
                    g[i][j] = cs[u2];
                } else {
                    g[i][j] = cs[u3];
                }
            }
        }
    }

    cout << siz << "\n";
    for (int i = 0; i < siz; ++ i){
        for (int j = 0; j < siz; ++ j){
            cout << g[i][j];
        }
        cout << "\n";
    }
}
