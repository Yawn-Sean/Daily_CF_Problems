#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}
struct bit2d{
    vector <vector<int>> g;
    int n, m;
    bit2d(){}
    bit2d(int n, int m): g(n+1, vector<int>(m+1)), n(n), m(m){}
    void modify(int x, int y, int d){
        for (int i = x; i <= n; i += i&-i){
            for (int j = y; j <= m; j += j&-j){
                g[i][j] += d;
            }
        }
    }
    int query(int x, int y){
        int res = 0;
        for (int i = x; i > 0; i -= i&-i){
            for (int j = y; j > 0; j -= j&-j){
                res += g[i][j];
            }
        }
        return res;
    }
    int query(int x, int y, int k){
        return query(x, y) - query(x-k, y) - query(x, y-k) + query(x-k, y-k);
    }
};
void solve(){
    using ary3 = array<int,3>;

    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector <ary3> seq;
    for (int i = 0,x,y,t; i < q; ++ i){
        cin >> x >> y >> t;
        seq.push_back({x,y,t});
    }
    sort(seq.begin(), seq.end(), [&](ary3&u, ary3&v){
        return u[2] < v[2];
    });

    bit2d Y(n, m);
    auto check = [&]()->bool{
        for (int i = k; i <= n; ++ i){
            for (int j = k; j <= m; ++ j){
                if (Y.query(i, j, k) == k*k){
                    return true;
                }
            }
        }
        return false;
    };

    int j = -1;
    auto moves = [&](int mid)->void{
        while (j < mid){
            j += 1;
            Y.modify(seq[j][0], seq[j][1], 1);
        }
        while (j > mid){
            Y.modify(seq[j][0], seq[j][1], -1);
            j -= 1;
        }
    };

    int l = 0, r = q-1;
    if (l <= r){
        while (l < r){
            int mid = (l+r) >> 1;
            moves(mid);
            if (check()) r = mid;
            else l = mid+1;
        }
        moves(l);
    }

    if (check()) cout << seq[l][2] << "\n";
    else cout << -1 << "\n";
}
