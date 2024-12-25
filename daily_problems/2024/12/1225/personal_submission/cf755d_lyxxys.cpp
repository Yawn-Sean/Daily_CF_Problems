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
    int n, k;
    cin >> n >> k;
    Yint Y(n);
    int cur = 1;
    i64 res = 1;
    for (int i = 1; i <= n; ++ i){
        if (k <= n/2){   // 如果 k <= n/2，弧[cur,cur+k]贡献
            if (cur < n){
                res += Y.query(cur, min(cur+k,n));
            }
            if (cur+k > n){
                res += Y.query((cur+k)%n-1);
            }
        } else {    // 如果 k > n/2，弧[cur,cur+k]的补集贡献
            if (cur+k <= n){  
                res += Y.query(cur-1) + Y.query(cur+k, n);
            } else {
                res += Y.query(cur+k-n, cur-1);
            }
        }
        res += 1;
        Y.update(cur, 1);
        cur += k;
        if (cur > n) cur -= n;
        Y.update(cur, 1);
        if (i > 1) cout << " ";
        cout << res;
    }
    cout << "\n";
}
