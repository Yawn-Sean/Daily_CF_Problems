#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
template <class T> struct fenwick {
    vector <T> info;
    int n;
    fenwick(){}
    fenwick(int n): info(n+1), n(n){}
    void update(int x, T val){
        while (x <= n){
            info[x] += val;
            x += x&-x;
        }
    }
    T query(int x){
        T res = 0;
        while (x){
            res += info[x];
            x -= x&-x;
        }
        return res;
    }
    T query(int lo, int hi){
        return query(hi) - query(lo);
    }
    T select(T kth){
        T ans = 0, lst = 0;
        for (int i = 20; i >= 0; -- i){
            ans += 1 << i;
            if (ans >= n || lst+info[ans] >= kth) ans -= 1 << i;
            else lst += 1 << i;
        }
        return ans+1;
    }
};
void solve(){
    using Yint = fenwick<int>;
    int n, q;
    cin >> n;
    vector <int> A(n+2), loc(n+2), f(n+1), chain(n+1);
    loc[n+1] = n+1;
    for (int i = 1; i <= n; ++ i){
        cin >> A[i];
        loc[A[i]] = i;
        f[A[i]] = f[A[i]-1] + 1;
    }

    Yint Y(n+1);
    int cur = n;
    while (cur > 0){
        int len = f[cur];
        Y.update(cur-len+1, 1);
        for (int j = cur-1; j > cur-len; -- j){
            chain[j] = 1;
        }
        cur = cur - len;
    }

    auto chge = [&](int x, int pos)->void{  // 把 x 移到 pos 这个 位置
        int j = loc[x];
        if (pos > j){    // 位置后移，前面形成，后面断开
            if (loc[x-1] >= j && pos >= loc[x-1] && !chain[x-1]){
                Y.update(x, -1);
                chain[x-1] = 1;
            }
            if (loc[x+1] >= j && pos >= loc[x+1] && chain[x]){
                Y.update(x+1, 1);
                chain[x] = 0;
            }
        } else {        // 位置前挪，前面断开，后面形成
            if (j >= loc[x-1] && pos <= loc[x-1] && chain[x-1]){
                Y.update(x, 1);
                chain[x-1] = 0;
            }
            if (j >= loc[x+1] && pos <= loc[x+1] && !chain[x]){
                Y.update(x+1, -1);
                chain[x] = 1;
            }
        }
        loc[x] = pos;
    };

    cin >> q;
    while (q--){
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1){
            cout << Y.query(x, y) + 1 << "\n";
        } else {
            int lst = A[x];
            chge(A[x], y), A[x] = A[y];
            chge(A[y], x), A[y] = lst;
        }
    }
}
